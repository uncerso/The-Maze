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
	OpenGLDrawer(OpenGLContext * openGLContext, int frequencyHz = 76);
	~OpenGLDrawer() noexcept = default;

	void changeFrequency(int frequencyHz) noexcept;

	void setBounds(int shiftFromLeftSide, int shiftFromBottomSide, int parentWidthInPixels, int parentHeightInPixels) noexcept;

	void loadData(std::unique_ptr<Shape> && shapeToDraw);

private:
	OpenGLContext * openGLContext;
	int frameCounter;
	CustomTimer timer;
	int glViewWidthInPixels, glViewHeightInPixels;
	int shiftFromLeftSideInPixels, shiftFromBottomSideInPixels;

	const GLchar * vertexShaderSource;
	const GLchar * fragmentShaderSource;
	std::unique_ptr<OpenGLShaderProgram> shader;
	std::unique_ptr<OpenGLShaderProgram::Attribute> position;
	std::unique_ptr<OpenGLShaderProgram::Uniform> color;
	std::unique_ptr<OpenGLShaderProgram::Uniform> widthAndHeightToNormalize;
	std::unique_ptr<OpenGLShaderProgram::Uniform> shiftsFromLeftBottomCorner;

	std::unique_ptr<Shape> shape;

	int frequencyHz;
	std::atomic<bool> needDrawNewIteration;
	std::atomic<bool> needInitVao;
	std::optional<GLuint> vao;

	void createShaders();

	void newOpenGLContextCreated() override;
	void renderOpenGL() override;
	void openGLContextClosing() noexcept override;

	void updateUniformsAboutShiftsAndNormalize() const noexcept;

	void initVao();

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OpenGLDrawer)
};