#include "MazeGenerator.h"
#include <queue>
#include <cassert>

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
			amountOfInteriors = sidewinderGenerator(width, height);
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

	while (!queue.empty()) {
		auto th = queue.front();
		queue.pop();
		data[dataPos++] = static_cast<float>(th.snd);
		data[dataPos++] = static_cast<float>(th.fst);

		for (int i = 0, iend = (withWalls ? aroundPointsSize : aroundPointsSizeShort); i < iend; i += 2) {
			int newY = th.fst + aroundPoints[i];
			int newX = th.snd + aroundPoints[i + 1];
			if (insideMatrix(newX, newY))
				if (matrix[newY][newX] == State::interior && i < aroundPointsSizeShort) {
					queue.push({ newY, newX });
					nonConstThis->matrix[newY][newX] = State::markedInterior;
				}
				else if (withWalls && matrix[newY][newX] == State::wall) {
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
	return xend // top line (first loop)
		+ yend - 1 // right line - intersection with top line (second loop)
		+ ((((width - 1) >> 1) * ((height - 1) >> 1)) << 1); // other point (third loop) [p.s. (2 (point itself + up or right point) * (w - 1) // 2 * (h - 1) // 2)]
}

int MazeGenerator::sidewinderGenerator(int width, int height) { return width + height; }