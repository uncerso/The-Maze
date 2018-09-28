#include "PointsToDraw.h"

const float * PointsToDraw::getRawData() const noexcept {
	return data.data();
}

//Return: start position and interval size
Pair<int, int> PointsToDraw::operator[](unsigned int intervalNumver) const {
	return Pair<int, int>(intervals[intervalNumver], intervals[intervalNumver + 1] - intervals[intervalNumver]);
}

int PointsToDraw::amountOfIntervals() const noexcept {
	return static_cast<int>(intervals.size() - 1);
}

std::vector<float> & PointsToDraw::getData() noexcept {
	return data;
}

unsigned int PointsToDraw::getRawDataSize() const noexcept {
	return static_cast<unsigned int>(data.size());
}