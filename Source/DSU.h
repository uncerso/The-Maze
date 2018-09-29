#pragma once

#include <vector>

class DSU {
public:
	DSU(size_t totalSize);

	int find(int num);
	void merge(int first, int second);

private:
	std::vector<int> parents;
	std::vector<int> rank;
};