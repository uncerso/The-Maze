#include "OpenGLDrawer.h"
#include "MazeGenerator.h"

OpenGLDrawer::OpenGLDrawer(OpenGLContext * openGLContext, int frequencyHz)
	: openGLContext(openGLContext)
	, frameCounter(0)
	, glViewWidthInPixels(1)
	, glViewHeightInPixels(1)
	, shiftFromLeftSideInPixels(0)
	, shiftFromBottomSideInPixels(0)
{
	jassert(openGLContext != nullptr);
	openGLContext->setRenderer(this);
	timer.setCallback([this] { this->openGLContext->triggerRepaint(); });
	timer.startTimerHz(frequencyHz);
}

void OpenGLDrawer::newOpenGLContextCreated() {
	createShaders();
	shader->use();
}

void OpenGLDrawer::openGLContextClosing() noexcept {
	shader.reset();
}

void OpenGLDrawer::changeFrequency(int frequencyHz) noexcept {
	timer.stopTimer();
	timer.startTimerHz(frequencyHz);
}

void OpenGLDrawer::setBounds(int shiftFromLeftSide, int shiftFromBottomSide, int parentWidthInPixels, int parentHeightInPixels) noexcept {
	shiftFromLeftSideInPixels = shiftFromLeftSide;
	shiftFromBottomSideInPixels = shiftFromBottomSide;
	glViewWidthInPixels = parentWidthInPixels;
	glViewHeightInPixels = parentHeightInPixels;
}

void OpenGLDrawer::updateUniformsAboutShiftsAndNormalize() const noexcept {
	widthAndHeightToNormalize->set(static_cast<GLfloat>(glViewWidthInPixels), static_cast<GLfloat>(glViewHeightInPixels));
	shiftsFromLeftBottomCorner->set(static_cast<GLfloat>(2.0 * shiftFromLeftSideInPixels / glViewWidthInPixels), static_cast<GLfloat>(2.0 * shiftFromBottomSideInPixels / glViewHeightInPixels));
}

void OpenGLDrawer::renderOpenGL() {
	jassert(openGLContext->isActive());
	++frameCounter;
	OpenGLHelpers::clear(Colours::black);
	shader->use();
	GLuint vao;
	openGLContext->extensions.glGenBuffers(1, &vao);
	openGLContext->extensions.glBindBuffer(GL_ARRAY_BUFFER, vao);
	openGLContext->extensions.glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * a.size(), a.data(), GL_STREAM_DRAW);
	openGLContext->extensions.glVertexAttribPointer(position->attributeID, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	openGLContext->extensions.glEnableVertexAttribArray(position->attributeID);

	auto t = frameCounter % tryColor.size();
	color->set(tryColor[t].getRed() / 255.0f, tryColor[t].getGreen() / 255.0f, tryColor[t].getBlue() / 255.0f);
	updateUniformsAboutShiftsAndNormalize();
	glDrawArrays(GL_TRIANGLES, 0, 3);

	openGLContext->extensions.glDisableVertexAttribArray(position->attributeID);
	openGLContext->extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
	openGLContext->extensions.glDeleteBuffers(1, &vao);
}

void OpenGLDrawer::createShaders() {
	vertexShaderSource =
		"#version 330\n"
		"attribute vec2 position;\n"
		"uniform vec2 widthAndHeightToNormalize;\n"
		"uniform vec2 shiftsFromLeftBottomCorner;\n"
		"void main(){\n"
		"gl_Position=vec4(2 * position.x / widthAndHeightToNormalize.x - 1 + shiftsFromLeftBottomCorner.x, 2 * position.y / widthAndHeightToNormalize.y - 1 + shiftsFromLeftBottomCorner.y, 0.0f, 1.0f);\n"
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
		widthAndHeightToNormalize.reset(new OpenGLShaderProgram::Uniform(*shader, "widthAndHeightToNormalize"));
		shiftsFromLeftBottomCorner.reset(new OpenGLShaderProgram::Uniform(*shader, "shiftsFromLeftBottomCorner"));
	}
	else
		std::cerr << newShader->getLastError();
	color->set(0.1f, 0.1f, 0.1f);
	updateUniformsAboutShiftsAndNormalize();
}