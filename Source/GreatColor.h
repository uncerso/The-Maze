#pragma once
#include <vector>
#include "Color.h"

class GreatColor {
public:
	GreatColor();
	~GreatColor() = default;

	Color getNextColor(unsigned int skipping = 0) noexcept;

private:
	static const std::vector<Color> color;
	int pos;
};
