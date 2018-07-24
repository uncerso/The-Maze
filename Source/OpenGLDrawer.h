#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class OpenGLDrawer
	: public OpenGLAppComponent
{
public:
	OpenGLDrawer();
//	OpenGLDrawer() = default;
	~OpenGLDrawer();

	void initialise() override;
	void shutdown() override;
	void render() override;

	void paint(Graphics&) override;

	template<class T>
	// func has type 'std::function<void()>'
	void afterRender(T && func);

private:
	const GLchar* vertexShaderSource;
	const GLchar* fragmentShaderSource;
	std::unique_ptr<OpenGLShaderProgram> shader;
	std::unique_ptr<OpenGLShaderProgram::Attribute> position;
	std::unique_ptr<OpenGLShaderProgram::Uniform> color;

	std::function<void(Graphics & g)> useAfterRender;

	std::vector<float> a = {-0.5, -0.5, 0, 0.5, 0.5, -0.5};
	//std::vector<float> a = { 100, 100, 300, 300, 100, 500 };

	void createShaders();

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OpenGLDrawer)
};

template<class T>
void OpenGLDrawer::afterRender(T && func) {
	useAfterRender = std::forward<T>(func);
}