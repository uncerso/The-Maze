#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "CustomTimer.h"
#include "GreatColor.h"
#include "Shape.h"
#include <optional>

class OpenGLDrawer
	: private OpenGLRenderer
{
public:
	enum class ShaderMode {dense, sparse};
	OpenGLDrawer(OpenGLContext * openGLContext, int delayInMs = 1);
	~OpenGLDrawer() noexcept = default;

	void changeFrequency(int delayInMs) noexcept;

	void setBounds(int shiftFromLeftSide, int shiftFromBottomSide, float parentWidthInPixels, float parentHeightInPixels) noexcept;

	void loadData(std::unique_ptr<Shape> && shapeToDraw, ShaderMode shaderMode);

	void setPointSize(int size);

private:
	OpenGLContext * openGLContext;
	std::atomic<int> lostFrameCounter;
	CustomTimer timer;
	float glViewWidthInPixels, glViewHeightInPixels;
	int shiftFromLeftSideInPixels, shiftFromBottomSideInPixels;
	int pointSize;

	const GLchar * vertexShaderSource;
	const GLchar * fragmentShaderSource;
	const GLchar * denseVertexShaderSource;
	const GLchar * denseFragmentShaderSource;
	std::unique_ptr<OpenGLShaderProgram> denseShader;
	std::unique_ptr<OpenGLShaderProgram> shader;
	std::unique_ptr<OpenGLShaderProgram::Attribute> densePosition;
	std::unique_ptr<OpenGLShaderProgram::Attribute> position;
	std::unique_ptr<OpenGLShaderProgram::Attribute> denseColor;
	std::unique_ptr<OpenGLShaderProgram::Uniform> color;
	std::unique_ptr<OpenGLShaderProgram::Uniform> widthAndHeightToNormalize;
	std::unique_ptr<OpenGLShaderProgram::Uniform> shiftsFromLeftBottomCorner;
	std::unique_ptr<OpenGLShaderProgram::Uniform> denseWidthAndHeightToNormalize;
	std::unique_ptr<OpenGLShaderProgram::Uniform> denseShiftsFromLeftBottomCorner;

	std::unique_ptr<Shape> shape;

	int timerFrequencyInMs;
	std::atomic<bool> needInitVao;
	std::optional<GLuint> vao;
	std::optional<GLuint> denseVao;

	ShaderMode actualShaderMode;

	void createShaders();

	void newOpenGLContextCreated() override;
	void renderOpenGL() override;
	void openGLContextClosing() noexcept override;

	void updateUniformsAboutShiftsAndNormalize() const noexcept;

	void initVao();

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OpenGLDrawer)
};
