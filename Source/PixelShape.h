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
	// func has type 'std::function<Color(unsigned int)>'
	PixelShape(PointsToDraw && points, T && func);
	~PixelShape() = default;

	void draw(OpenGLShaderProgram::Uniform * color) override;
	const float * getRawData() const noexcept override;
	unsigned int getRawDataSize() const noexcept override;

private:
	const PointsToDraw points;
	std::vector<Color> colors;
	GreatColor gc;
};

template<class T>
PixelShape::PixelShape(PointsToDraw && points, T && func)
	: points(std::move(points))
{
	for (int i = 0; i < points.amountOfIntervals(); ++i)
		colors.emplace_back(func(i));
}
