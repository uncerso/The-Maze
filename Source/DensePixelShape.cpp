#include "DensePixelShape.h"

bool DensePixelShape::incrementDraw(OpenGLShaderProgram::Uniform *) {
	if (iteration != points.amountOfIntervals()) {
		auto const & temp = points[iteration];
		glDrawArrays(GL_POINTS, temp.fst, temp.snd);
		++iteration;
	}
	return iteration == points.amountOfIntervals();
}

void DensePixelShape::repeint(OpenGLShaderProgram::Uniform *) {
	if (iteration == 0) return;
	auto const & temp = points[iteration - 1];
	glDrawArrays(GL_POINTS, 0, temp.fst + temp.snd);
}

const float * DensePixelShape::getRawData() const noexcept {
	return points.getRawData();
}

unsigned int DensePixelShape::getRawDataSize() const noexcept {
	return points.getRawDataSize();
}
