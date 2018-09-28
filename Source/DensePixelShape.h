#pragma once
#include <vector>
#include "Shape.h"
#include "Color.h"
#include "PointsToDraw.h"
#include <functional>
#include "GreatColor.h"

class DensePixelShape
	: public Shape
{
public:
	template <class T>
	// func has type 'std::function<Color(unsigned int, unsigned int)>'
	DensePixelShape(PointsToDraw && points, T && func, bool oneFrame = false);
	~DensePixelShape() = default;

	bool incrementDraw(OpenGLShaderProgram::Uniform *) override;
	void repeint(OpenGLShaderProgram::Uniform *) override;
	const float * getRawData() const noexcept override;
	unsigned int getRawDataSize() const noexcept override;

private:
	PointsToDraw points;
	int iteration;
};

template<class T>
DensePixelShape::DensePixelShape(PointsToDraw && points, T && func, bool oneFrame)
	: points(std::move(points))
	, iteration(0)
{
	auto &rowData = this->points.getData();
	auto currentPoint = 0;
	for (int i = 0, iend = this->points.amountOfIntervals(); i < iend; ++i) {
		auto colour = func(i, iend);
		for (auto[pos, size] = this->points[i]; size > 0; --size, currentPoint += 5) {
			rowData[currentPoint + 2] = colour.red();
			rowData[currentPoint + 3] = colour.green();
			rowData[currentPoint + 4] = colour.blue();
		}
	}
	if (oneFrame)
		iteration = this->points.amountOfIntervals() - 1;
}
