#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "CustomTimer.h"

class OpenGLDrawer
	: private OpenGLRenderer
{
public:
	OpenGLDrawer(OpenGLContext * openGLContext, int frequencyHz = 75);
	~OpenGLDrawer();

	void changeFrequency(int frequencyHz);

private:
	OpenGLContext * openGLContext;
	int frameCounter;
	CustomTimer timer;

	const GLchar * vertexShaderSource;
	const GLchar * fragmentShaderSource;
	std::unique_ptr<OpenGLShaderProgram> shader;
	std::unique_ptr<OpenGLShaderProgram::Attribute> position;
	std::unique_ptr<OpenGLShaderProgram::Uniform> color;

	std::vector<float> a = {-0.5, -0.5, 0, 0.5, 0.5, -0.5};

	void createShaders();

	void newOpenGLContextCreated() override;
	void renderOpenGL() override;
	void openGLContextClosing() override;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OpenGLDrawer)
};