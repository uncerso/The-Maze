#include "MazeGenerator.h"
#include <queue>
#include <map>
#include <cassert>
#include "Triple.h"

MazeGenerator::MazeGenerator()
	: lastSeed(0)
	, lastWidth(0)
	, lastHeight(0)
	, amountOfInteriors(0)
	, lastMazeType(MazeType::binaryTree)
{}

void MazeGenerator::fillMatrix(State state) noexcept {
	for (auto & x : matrix)
		for (auto & t : x)
			t = state;
}

void MazeGenerator::resizeMatrix(int width, int height) {
	matrix.resize(height);
	for (auto & x : matrix)
		x.resize(width);
}

void MazeGenerator::generate(int seed, int width, int height, MazeType mazeType) {
	if (seed == lastSeed && width == lastWidth && height == lastHeight && mazeType == lastMazeType) return;
	randomGenerator = std::mt19937(seed);
	resizeMatrix(width, height);
	fillMatrix();
	switch (mazeType) {
		case MazeType::binaryTree:
			amountOfInteriors = binaryTreeGenerator(width, height);
			break;
		case MazeType::sidewinder:
			amountOfInteriors = sidewinderGenerator(width, height, 15);
			break;
		case MazeType::noname:
			amountOfInteriors = nonameGenerator(width, height, 0, 0);
			break;
		default: break;
	}
	lastSeed = seed;
	lastWidth = width;
	lastHeight = height;
	lastMazeType = mazeType;
}

bool MazeGenerator::insideMatrix(int x, int y) const noexcept {
	return 0 <= y && y < matrix.size() && 0 <= x && x < matrix[0].size();
}

int MazeGenerator::evenEdgeFiller(int width, int height) {
	int ans = 0;
	if (!(width & 1)) {
		for (int y = 0; y < height; y += 2)
			matrix[y][width - 1] = State::interior;
		ans += height / 2;
	}
	if (!(height & 1)) {
		for (int x = 0; x < width; x += 2)
			matrix[height - 1][x] = State::interior;
		ans += width / 2;
	}
	return ans;
}

PointsToDraw MazeGenerator::getMazeAsPointsToDraw(DrawType drawType, int startX, int startY) const {
	std::vector<float> data;
	std::vector<int> intervals;

	if (drawType == DrawType::oneFrame)
		oneFramePainting(data, intervals);
	else
		wavePainting(startX, startY, data, intervals, DrawType::withWalls == drawType);

	return PointsToDraw(std::move(data), std::move(intervals));
}

void MazeGenerator::oneFramePainting(std::vector<float> & data, std::vector<int> & intervals) const {
	data.resize(amountOfInteriors << 1);
	intervals = { 0, amountOfInteriors };
	int pos = 0;
	for (int y = 0, yend = static_cast<int>(matrix.size()); y < yend; ++y)
		for (int x = 0, xend = static_cast<int>(matrix[0].size()); x < xend; ++x)
			if (matrix[y][x] == State::interior) {
				data[pos] = static_cast<float>(x);
				data[pos + 1] = static_cast<float>(y);
				pos += 2;
			}
	assert(pos == data.size());
}

void MazeGenerator::wavePainting(int startX, int startY, std::vector<float> & data, std::vector<int> & intervals, bool withWalls) const {
	constexpr char aroundPointsSize = 16;
	constexpr char aroundPointsSizeShort = 8;
	constexpr char aroundPoints[aroundPointsSize] = {
		1, 0, /**/ 0, 1, /**/ -1, 0, /**/ 0, -1,
		1, 1, /**/ -1, 1, /**/ -1, -1, /**/ 1, -1
	};

	auto * nonConstThis = const_cast<MazeGenerator *>(this);

	data.resize((withWalls ? matrix.size() * matrix[0].size() * 2 : amountOfInteriors << 1));

	if (matrix[startY][startX] == State::wall)
		for (int i = 0; i < aroundPointsSize; i += 2) {
			if (matrix[startY + aroundPoints[i]][startX + aroundPoints[i + 1]] == State::interior) {
				startY += aroundPoints[i];
				startX += aroundPoints[i + 1];
				break;
			}
		}
	assert(matrix[startY][startX] == State::interior);

	std::queue<Pair<int, int> > queue;
	int dataPos = 0;
	intervals = { 0 };
	int amountOfPointsLeftOnTheCurrentInterval = 1;
	queue.push({ startY, startX });
	nonConstThis->matrix[startY][startX] = State::markedInterior;

	auto aroundBorder = [&mt = matrix, h = matrix.size() - 1, w = matrix[0].size() - 1](int x, int y) {
		return
			0 < x && (mt[y][x - 1] == State::wall || mt[y][x - 1] == State::markedWall) &&
			x < w && (mt[y][x + 1] == State::wall || mt[y][x + 1] == State::markedWall) &&
			0 < y && (mt[y - 1][x] == State::wall || mt[y - 1][x] == State::markedWall) &&
			y < h && (mt[y + 1][x] == State::wall || mt[y + 1][x] == State::markedWall);
	};

	while (!queue.empty()) {
		auto const th = queue.front();
		queue.pop();
		data[dataPos++] = static_cast<float>(th.snd);
		data[dataPos++] = static_cast<float>(th.fst);

		for (int i = 0, iend = (withWalls ? aroundPointsSize : aroundPointsSizeShort); i < iend; i += 2) {
			int const newY = th.fst + aroundPoints[i];
			int const newX = th.snd + aroundPoints[i + 1];
			if (insideMatrix(newX, newY))
				if (matrix[newY][newX] == State::interior && i < aroundPointsSizeShort) {
					queue.push({ newY, newX });
					nonConstThis->matrix[newY][newX] = State::markedInterior;
				}
				else if (withWalls && matrix[newY][newX] == State::wall && (i < aroundPointsSizeShort || aroundBorder(newX, newY))) {
					data[dataPos++] = static_cast<float>(newX);
					data[dataPos++] = static_cast<float>(newY);
					nonConstThis->matrix[newY][newX] = State::markedWall;
				}
		}

		if (--amountOfPointsLeftOnTheCurrentInterval == 0) {
			amountOfPointsLeftOnTheCurrentInterval = static_cast<int>(queue.size());
			intervals.emplace_back(dataPos >> 1);
		}
	}
	assert(amountOfPointsLeftOnTheCurrentInterval == 0);
	assert(dataPos == data.size());
	intervals.emplace_back(dataPos >> 1);

	for (auto & x : nonConstThis->matrix)
		for (auto & t : x)
			if (t == State::markedInterior)
				t = State::interior;
			else if (t == State::markedWall)
				t = State::wall;
}

int MazeGenerator::binaryTreeGenerator(int const width, int const height) {
	const int xend = width - !(width & 1);
	const int yend = height - !(height & 1);

	for (int x = 0; x < xend; ++x)
		matrix[0][x] = State::interior;

	for (int y = 1; y < yend; ++y)
		matrix[y][xend - 1] = State::interior;

	for (int y = 2; y < height; y += 2)
		for (int x = 0; x < width - 3; x += 2) {
			matrix[y][x] = State::interior;
			if (randomGenerator() & 1)
				matrix[y - 1][x] = State::interior;
			else
				matrix[y][x + 1] = State::interior;
		}
	return ((height + 1) >> 1) * (width + (width & 1)) - 1 + evenEdgeFiller(width, height);
}

int MazeGenerator::sidewinderGenerator(int width, int height, int /*maxBlockSize*/) {
	for (int x = 0, xend = width - !(width & 1); x < xend; ++x)
		matrix[0][x] = State::interior;

	for (int y = 2; y < height; y += 2) {
		int leftOnTheCurrentY = (width + 1) >> 1;
		int x = 0;
		while (leftOnTheCurrentY > 0) {
			//int blockSize = randomGenerator() % std::min(leftOnTheCurrentY, maxBlockSize) + 1; // this block will be interior
			int blockSize = 1; // this block will be interior
			while (blockSize != leftOnTheCurrentY && randomGenerator() & 1)
				++blockSize;
			leftOnTheCurrentY -= blockSize;
			matrix[y - 1][x + ((randomGenerator() % blockSize) << 1)] = State::interior; // connection this block with upper
			for (int xend = x + (blockSize << 1) - 1; x < xend; ++x)
				matrix[y][x] = State::interior;
			++x; // otherwise x will point to the wall
		}
	}

	return ((height + 1) >> 1) * (width + (width & 1)) - 1 + evenEdgeFiller(width, height);
}

int MazeGenerator::nonameGenerator(int width, int height, int startX, int startY) {
	using uchar = unsigned char;
	using std::make_pair;
	constexpr uchar up = 1;
	constexpr uchar left = 2;
	constexpr uchar right = 4;
	constexpr uchar down = 8;

	constexpr char aroundPointsSize = 8;
	constexpr char aroundPointsFrom[aroundPointsSize] = { up, 0, /**/ left, 0, /**/ down, 0, /**/ right };
	constexpr char aroundPointsX2[aroundPointsSize] = { 2, 0, /**/ 0, 2, /**/ -2, 0, /**/ 0, -2 };

	startX -= startX & 1;
	startY -= startY & 1;

	std::multimap<unsigned int, Triple<int, int, uchar> > priorityQueue;
	priorityQueue.emplace(make_pair(0u, Triple<int, int, uchar>(startY, startX, 0u)));

	while (!priorityQueue.empty()) {
		auto const it = priorityQueue.begin();
		auto const th = it->second;
		priorityQueue.erase(it);

		if (matrix[th.fst][th.snd] == State::interior) continue;
		matrix[th.fst][th.snd] = State::interior;
		matrix[th.fst + (th.trd == down) - (th.trd == up)][th.snd + (th.trd == right) - (th.trd == left)] = State::interior;

		for (int i = 0; i < aroundPointsSize; i += 2) {
			int const newY = th.fst + aroundPointsX2[i];
			int const newX = th.snd + aroundPointsX2[i + 1];
			if (insideMatrix(newX, newY))
				if (matrix[newY][newX] == State::wall)
					priorityQueue.emplace(make_pair(randomGenerator(), Triple<int, int, uchar>(newY, newX, aroundPointsFrom[i])));
		}
	}

	return ((height + 1) >> 1) * (width + (width & 1)) - 1 + evenEdgeFiller(width, height);
}