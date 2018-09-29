#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Shape {
public:
	Shape() = default;
	virtual ~Shape() = default;
	Shape(Shape const &) = default;
	Shape(Shape &&) = default;
	Shape & operator = (Shape const &) = default;
	Shape & operator = (Shape &&) = default;

	virtual bool incrementDraw(OpenGLShaderProgram::Uniform *) = 0;
	virtual void repeint(OpenGLShaderProgram::Uniform *) = 0;
	virtual const float * getRawData() const noexcept = 0;
	virtual unsigned int getRawDataSize() const noexcept = 0;
};
