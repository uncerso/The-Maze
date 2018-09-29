#include "PixelShape.h"

bool PixelShape::incrementDraw(OpenGLShaderProgram::Uniform * color) {
	if (iteration != points.amountOfIntervals()) {
		auto const & tmp = colors[iteration];
		color->set(tmp.red(), tmp.green(), tmp.blue());
		auto const & temp = points[iteration];
		glDrawArrays(GL_POINTS, temp.fst, temp.snd);
		++iteration;
	}
	return iteration == points.amountOfIntervals();
}

void PixelShape::repeint(OpenGLShaderProgram::Uniform * color) {
	for (int i = 0; i < iteration; ++i) {
		auto const & tmp = colors[i];
		color->set(tmp.red(), tmp.green(), tmp.blue());
		auto const & temp = points[i];
		glDrawArrays(GL_POINTS, temp.fst, temp.snd);
	}
}

const float * PixelShape::getRawData() const noexcept {
	return points.getRawData();
}

unsigned int PixelShape::getRawDataSize() const noexcept {
	return points.getRawDataSize();
}
