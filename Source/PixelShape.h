#pragma once
#include <vector>
#include "Shape.h"
#include "Color.h"
#include "PointsToDraw.h"
#include <functional>
#include "GreatColor.h"

class PixelShape
	: public Shape
{
public:
	template <class T>
	// func has type 'std::function<Color(unsigned int, unsigned int)>'
	PixelShape(PointsToDraw && points, T && func, bool oneFrame = false);
	~PixelShape() = default;

	bool incrementDraw(OpenGLShaderProgram::Uniform * color) override;
	void repeint(OpenGLShaderProgram::Uniform * color) override;
	const float * getRawData() const noexcept override;
	unsigned int getRawDataSize() const noexcept override;

private:
	PointsToDraw points;
	std::vector<Color> colors;
	int iteration;
};

template<class T>
PixelShape::PixelShape(PointsToDraw && points, T && func, bool oneFrame)
	: points(std::move(points))
	, iteration(0)
{
	for (int i = 0, iend = this->points.amountOfIntervals(); i < iend; ++i)
		colors.emplace_back(func(i, iend));
	if (oneFrame)
		iteration = this->points.amountOfIntervals() - 1;
}
