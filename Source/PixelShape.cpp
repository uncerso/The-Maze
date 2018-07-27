#include "PixelShape.h"

void PixelShape::draw(OpenGLShaderProgram::Uniform * color) {
	auto const & tmp = gc.getNextColor();
	color->set(tmp.red(), tmp.green(), tmp.blue());
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

const float * PixelShape::getRawData() const noexcept {
	return points.getRawData();
}

unsigned int PixelShape::getRawDataSize() const noexcept {
	return points.getRawDataSize();
}
