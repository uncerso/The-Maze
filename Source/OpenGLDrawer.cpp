#include "OpenGLDrawer.h"

OpenGLDrawer::OpenGLDrawer(OpenGLContext * openGLContext, int delayInMs)
	: openGLContext(openGLContext)
	, lostFrameCounter(0)
	, glViewWidthInPixels(1)
	, glViewHeightInPixels(1)
	, shiftFromLeftSideInPixels(0)
	, shiftFromBottomSideInPixels(0)
	, pointSize(1)
	, timerFrequencyInMs(delayInMs)
	, needInitVao(false)
{
	jassert(openGLContext != nullptr);
	openGLContext->setRenderer(this);
	timer.setCallback([this] { ++lostFrameCounter; /*this->openGLContext->triggerRepaint(); */});
}

void OpenGLDrawer::newOpenGLContextCreated() {
	createShaders();
	shader->use();
}

void OpenGLDrawer::openGLContextClosing() noexcept {
	shader.reset();
}

void OpenGLDrawer::changeFrequency(int delayInMs) noexcept {
	timerFrequencyInMs = delayInMs;
}

void OpenGLDrawer::setBounds(int shiftFromLeftSide, int shiftFromBottomSide, float parentWidthInPixels, float parentHeightInPixels) noexcept {
	shiftFromLeftSideInPixels = shiftFromLeftSide;
	shiftFromBottomSideInPixels = shiftFromBottomSide;
	glViewWidthInPixels = parentWidthInPixels;
	glViewHeightInPixels = parentHeightInPixels;
}

void OpenGLDrawer::updateUniformsAboutShiftsAndNormalize() const noexcept {
	widthAndHeightToNormalize->set(static_cast<GLfloat>(glViewWidthInPixels), static_cast<GLfloat>(glViewHeightInPixels));
	shiftsFromLeftBottomCorner->set(static_cast<GLfloat>((2.0 * shiftFromLeftSideInPixels + 1) / glViewWidthInPixels), static_cast<GLfloat>((2.0 * shiftFromBottomSideInPixels + 1) / glViewHeightInPixels));
}

void OpenGLDrawer::loadData(std::unique_ptr<Shape> && shapeToDraw) {
	shape = std::move(shapeToDraw);
	needInitVao = true;
	timer.startTimer(timerFrequencyInMs);
	openGLContext->setContinuousRepainting(true);
}

void OpenGLDrawer::setPointSize(int size) {
	pointSize = size;
}

void OpenGLDrawer::initVao() {
	jassert(openGLContext->isActive());
	if (vao.has_value())
		openGLContext->extensions.glDeleteBuffers(1, &vao.value());
	else
		vao.emplace();
	openGLContext->extensions.glGenBuffers(1, &vao.value());
	openGLContext->extensions.glBindBuffer(GL_ARRAY_BUFFER, vao.value());
	openGLContext->extensions.glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * shape->getRawDataSize(), shape->getRawData(), GL_STATIC_DRAW);
	openGLContext->extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLDrawer::renderOpenGL() {
	jassert(openGLContext->isActive());

	if (!shape) {
		OpenGLHelpers::clear(Colours::black);
		return;
	}

	shader->use();
	if (needInitVao) {
		initVao();
		needInitVao = false;
		glPointSize(static_cast<float>(pointSize));
	}

	if (!vao.has_value()) return;
	openGLContext->extensions.glBindBuffer(GL_ARRAY_BUFFER, vao.value());
	openGLContext->extensions.glVertexAttribPointer(position->attributeID, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	openGLContext->extensions.glEnableVertexAttribArray(position->attributeID);

	updateUniformsAboutShiftsAndNormalize();

	OpenGLHelpers::clear(Colours::black);
	shape->repeint(color.get());
	while (lostFrameCounter > 0) {
		if (shape->incrementDraw(color.get())) {
			timer.stopTimer();
			openGLContext->setContinuousRepainting(false);
			lostFrameCounter = 0;
			break;
		}
		--lostFrameCounter;
	}

	openGLContext->extensions.glDisableVertexAttribArray(position->attributeID);
	openGLContext->extensions.glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLDrawer::createShaders() {
	vertexShaderSource =
		"attribute vec2 position;\n"
		"uniform vec2 widthAndHeightToNormalize;\n"
		"uniform vec2 shiftsFromLeftBottomCorner;\n"
		"void main(){\n"
		"gl_Position=vec4(2.0f * position.x / widthAndHeightToNormalize.x - 1.0f + shiftsFromLeftBottomCorner.x, 2.0f * position.y / widthAndHeightToNormalize.y - 1.0f + shiftsFromLeftBottomCorner.y, 0.0f, 1.0f);\n"
		"}\0;";

	fragmentShaderSource =
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
