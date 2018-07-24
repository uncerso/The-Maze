#include "OpenGLDrawer.h"

OpenGLDrawer::OpenGLDrawer()
	: useAfterRender([](Graphics &) {})
{
	//openGLContext.setComponentPaintingEnabled(false);
}

void OpenGLDrawer::paint(Graphics &) {}

OpenGLDrawer::~OpenGLDrawer() {
	shutdownOpenGL();
}

void OpenGLDrawer::initialise() {
	createShaders();
	shader->use();
}

void OpenGLDrawer::shutdown() {
	shader.reset();
}

void OpenGLDrawer::render() {
	//glViewport(0, 0, getWidth(), getHeight());
	//OpenGLHelpers::clear(Colours::black);
	OpenGLHelpers::clear(Colours::darkorange);
	shader->use();
	GLuint vao;
	openGLContext.extensions.glGenBuffers(1, &vao);
	openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, vao);
	openGLContext.extensions.glBufferData(GL_ARRAY_BUFFER, sizeof(float) * a.size(), a.data(), GL_STREAM_DRAW);
	openGLContext.extensions.glVertexAttribPointer(position->attributeID, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (GLvoid*)0);
	openGLContext.extensions.glEnableVertexAttribArray(position->attributeID);

	auto fc = getFrameCounter() * 0.05;
	color->set(cos(fc), sin(fc), sin(fc)*cos(fc));

	glDrawArrays(GL_TRIANGLES, 0, 3);

	openGLContext.extensions.glDisableVertexAttribArray(position->attributeID);
	openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
	openGLContext.extensions.glDeleteBuffers(1, &vao);
	auto desktopScale = (float)openGLContext.getRenderingScale(); 
	std::unique_ptr<LowLevelGraphicsContext> glRenderer(createOpenGLGraphicsContext(openGLContext,
		roundToInt(desktopScale * getWidth()),
		roundToInt(desktopScale * getHeight())));
	//openGLContext
	Graphics g(*glRenderer);
	useAfterRender(g);
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

	auto newShader = std::make_unique<OpenGLShaderProgram>(openGLContext);
	if (newShader->addVertexShader(OpenGLHelpers::translateVertexShaderToV3(vertexShaderSource))
		&& newShader->addFragmentShader(OpenGLHelpers::translateFragmentShaderToV3(fragmentShaderSource))
		&& newShader->link()) {
		shader.reset(newShader.release());
		shader->use();

		jassert(openGLContext.extensions.glGetAttribLocation(shader->getProgramID(), "position") >= 0);
		position.reset(new OpenGLShaderProgram::Attribute(*shader, "position"));
		color.reset(new OpenGLShaderProgram::Uniform(*shader, "color"));
	}
	else
		std::cerr << newShader->getLastError();
	color->set(0.1, 0.1, 0.1);
}