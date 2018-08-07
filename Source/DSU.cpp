#include "DSU.h"
#include <cassert>

DSU::DSU(size_t totalSize)
	: parents(totalSize, -1)
	, rank(totalSize, 0)
{
}

int DSU::find(int num) {
	assert(0 <= num && num <= parents.size());
	if (parents[num] == -1) return num;
	return parents[num] = find(parents[num]);
}

void DSU::merge(int first, int second) {
	first = find(first);
	second = find(second);
	if (rank[first] < rank[second])
		std::swap(first, second);
	else if (rank[first] == rank[second])
		++rank[first];
	parents[second] = first;
}
