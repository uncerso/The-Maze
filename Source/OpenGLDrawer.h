#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "CustomTimer.h"

class OpenGLDrawer
	: private OpenGLRenderer
{
public:
	OpenGLDrawer(OpenGLContext * openGLContext, int frequencyHz = 75);
	~OpenGLDrawer() noexcept = default;

	void changeFrequency(int frequencyHz) noexcept;

	void setBounds(int shiftFromLeftSide, int shiftFromBottomSide, int parentWidthInPixels, int parentHeightInPixels) noexcept;

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

	std::vector<GLfloat> a = {0, 0, 50, 100, 100, 0};

	void createShaders();

	void newOpenGLContextCreated() override;
	void renderOpenGL() override;
	void openGLContextClosing() noexcept override;

	void updateUniformsAboutShiftsAndNormalize() const noexcept;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OpenGLDrawer)
};