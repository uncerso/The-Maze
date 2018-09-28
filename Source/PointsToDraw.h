#pragma once
#include <vector>
#include "Pair.h"
#pragma warning(disable : 4544)

class PointsToDraw {
public:
	template<
		class T,
		class U,
		class = std::enable_if_t<
		std::is_same_v<std::vector<float>, std::decay_t<T> >
		&&
		std::is_same_v<std::vector<int>, std::decay_t<U> >
		>
	>
		PointsToDraw(T && data, U && intervals);

	~PointsToDraw() = default;

	const float * getRawData() const noexcept;
	unsigned int getRawDataSize() const noexcept;

	Pair<int, int> operator[](unsigned int intervalNumver) const;

	int amountOfIntervals() const noexcept;
	std::vector<float> & getData() noexcept;

private:
	std::vector<float> data;
	std::vector<int> intervals;
};

template<
	class T,
	class U,
	class
>
PointsToDraw::PointsToDraw(T && data, U && intervals)
	: data(std::forward<T>(data))
	, intervals(std::forward<U>(intervals))
{}
