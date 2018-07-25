#include "OpenGLDrawer.h"

OpenGLDrawer::OpenGLDrawer(OpenGLContext * openGLContext, int frequencyHz)
	: openGLContext(openGLContext)
	, frameCounter(0)
{
	jassert(openGLContext != nullptr);
	openGLContext->setRenderer(this);
	timer.setCallback([this] { this->openGLContext->triggerRepaint(); });
	timer.startTimerHz(frequencyHz);
}

OpenGLDrawer::~OpenGLDrawer() {
	openGLContext->setRenderer(nullptr);
}

void OpenGLDrawer::newOpenGLContextCreated() {
	createShaders();
	shader->use();
}

void OpenGLDrawer::openGLContextClosing() {
	shader.reset();
}

void OpenGLDrawer::changeFrequency(int frequencyHz) {
	timer.stopTimer();
	timer.startTimerHz(frequencyHz);
}

void OpenGLDrawer::renderOpenGL() {
	jassert(openGLContext->isActive());
	++frameCounter;
	OpenGLHelpers::clear(Colours::darkorange);
	shader->use();
	GLuint vao;
	openGLContext->extensions.glGenBuffers(1, &vao);
	openGLContext->extensions.glBindBuffer(GL_ARRAY_BUFFER, vao);
	openGLContext->extensions.glBufferData(GL_ARRAY_BUFFER, sizeof(float) * a.size(), a.data(), GL_STREAM_DRAW);
	openGLContext->extensions.glVertexAttribPointer(position->attributeID, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (GLvoid*)0);
	openGLContext->extensions.glEnableVertexAttribArray(position->attributeID);

	auto fc = frameCounter * 0.05f;
	color->set(cos(fc), sin(fc), sin(fc)*cos(fc));

	glDrawArrays(GL_TRIANGLES, 0, 3);

	openGLContext->extensions.glDisableVertexAttribArray(position->attributeID);
	openGLContext->extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
	openGLContext->extensions.glDeleteBuffers(1, &vao);
}

void OpenGLDrawer::createShaders() {
	vertexShaderSource =
		"#version 330\n"
		"attribute vec2 position;\n"
		"void main(){\n"
		"gl_Position=vec4(position.x, position.y, 0.0f, 1.0f);\n"
		"}\0;";

	fragmentShaderSource =
		"#version 330\n"
		"uniform vec3 color;\n"
		"void main(){\n"
		"gl_FragColor=vec4(color, 1.0f);\n"
		"}\0";

	auto newShader = std::make_unique<OpenGLShaderProgram>(*openGLContext);
	if (newShader->addVertexShader(OpenGLHelpers::translateVertexShaderToV3(vertexShaderSource))
		&& newShader->addFragmentShader(OpenGLHelpers::translateFragmentShaderToV3(fragmentShaderSource))
		&& newShader->link()) {
		shader.reset(newShader.release());
		shader->use();

		jassert(openGLContext->extensions.glGetAttribLocation(shader->getProgramID(), "position") >= 0);
		position.reset(new OpenGLShaderProgram::Attribute(*shader, "position"));
		color.reset(new OpenGLShaderProgram::Uniform(*shader, "color"));
	}
	else
		std::cerr << newShader->getLastError();
	color->set(0.1f, 0.1f, 0.1f);
}