// #pragma comment(linker, "/STACK:1000000000")
#include "MazeGenerator.h"
#include "Triple.h"
#include "DSU.h"
#include "SystemHeapStack.h"
#include <queue>
#include <map>
#include <cassert>
#include <algorithm>
#include <functional>
#include <array>

#ifdef NDEBUG
#define massert(expression) ((void)0)
#else
#define massert(expression) { \
	if (!(expression)) { \
		dump(); \
		assert(expression); \
	} \
}

#include <fstream>
void MazeGenerator::dump() const {
	std::ofstream out("the_maze_dump.log");
	out << "seed: " << lastSeed << '\n';
	out << "width: " << lastWidth << '\n';
	out << "height: " << lastHeight << '\n';
	out << "maze type:" << static_cast<int>(lastMazeType) << '\n';
	out << "wall: #\n";
	out << "marked wall: *\n";
	out << "interior: -\n";
	out << "marked interior: ~\n";
	for (auto const & row : matrix) {
		for (auto const & el : row) {
			char c = ' ';
			if (el == State::wall) c = '#';
			if (el == State::markedWall) c = '*';
			if (el == State::interior) c = '-';
			if (el == State::markedInterior) c = '~';
			out << c;
		}
		out << '\n';
	}
}
#endif

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

void MazeGenerator::generate(unsigned int seed, int width, int height, MazeType mazeType) {
	assert(height > 0);
	assert(width > 0);

	if (seed == lastSeed && width == lastWidth && height == lastHeight && mazeType == lastMazeType) return;
	randomGenerator = std::mt19937(seed);
	resizeMatrix(width, height);
	fillMatrix();
	switch (mazeType) {
	case MazeType::binaryTree:
		binaryTreeGenerator(width, height);
		break;
	case MazeType::sidewinder:
		sidewinderGenerator(width, height);
		break;
	case MazeType::prime:
		primGenerator(0, 0);
		break;
	case MazeType::kruskal:
		kruskalGenerator(width, height);
		break;
	case MazeType::recursiveBacktracker:
		recursiveBacktrackerGenerator();
		break;
	case MazeType::recursiveDivision:
		recursiveDivisionGenerator(width, height);
		break;
	case MazeType::huntAndKill:
		huntAndKillGenerator(width, height);
		break;
	case MazeType::eller:
		ellerGenerator(width, height);
		break;
	default:
		// unknown algorithm
		assert(false);
		break;
	}
	evenEdgeFiller(width, height);
	amountOfInteriors = calculateAmountOfInteriors(width, height);
	lastSeed = seed;
	lastWidth = width;
	lastHeight = height;
	lastMazeType = mazeType;
}

int MazeGenerator::calculateAmountOfInteriors(int width, int height) const noexcept {
	return ((height + 1) >> 1) * (width + (width & 1)) - 1 +
		((height & 1) ? 0 : (width + 1) / 2) +
		((width & 1) ? 0 : (height + 1) / 2);
}

bool MazeGenerator::insideMatrix(int x, int y) const noexcept {
	return 0 <= y && y < matrix.size() && 0 <= x && x < matrix[0].size();
}

void MazeGenerator::evenEdgeFiller(int width, int height) {
	if (!(width & 1)) {
		for (int y = 0; y < height; y += 2)
			matrix[y][width - 1] = State::interior;
	}
	if (!(height & 1)) {
		for (int x = 0; x < width; x += 2)
			matrix[height - 1][x] = State::interior;
	}
}

PointsToDraw MazeGenerator::getMazeAsPointsToDraw(DrawType drawType, unsigned int const vertSize, int startX, int startY) const {
	assert(lastHeight > 0);
	assert(lastWidth > 0);
	assert(insideMatrix(startX, startY));
	assert(vertSize >= 2);

	std::vector<float> data;
	std::vector<int> intervals;

	if (drawType == DrawType::oneFrame)
		oneFramePainting(data, intervals, vertSize);
	else
		wavePainting(startX, startY, data, intervals, DrawType::withWalls == drawType, vertSize);

	return PointsToDraw(std::move(data), std::move(intervals));
}

void MazeGenerator::oneFramePainting(std::vector<float> & data, std::vector<int> & intervals, unsigned int const vertSize) const {
	data.resize(amountOfInteriors * vertSize);
	intervals = { 0, amountOfInteriors };
	int pos = 0;
	for (int y = 0, yend = static_cast<int>(matrix.size()); y < yend; ++y)
		for (int x = 0, xend = static_cast<int>(matrix[0].size()); x < xend; ++x)
			if (matrix[y][x] == State::interior) {
				data[pos] = static_cast<float>(x);
				data[pos + 1] = static_cast<float>(y);
				pos += vertSize;
			}
	massert(pos == data.size());
}

void MazeGenerator::wavePainting(int startX, int startY, std::vector<float> & data, std::vector<int> & intervals, bool withWalls, unsigned int const vertSize) const {
	constexpr char aroundPointsSize = 16;
	constexpr char aroundPointsSizeShort = 8;
	constexpr char aroundPoints[aroundPointsSize] = {
		1, 0, /**/ 0, 1, /**/ -1, 0, /**/ 0, -1,
		1, 1, /**/ -1, 1, /**/ -1, -1, /**/ 1, -1
	};

	auto * nonConstThis = const_cast<MazeGenerator *>(this);

	data.resize((withWalls ? matrix.size() * matrix[0].size() : amountOfInteriors) * vertSize);

	if (matrix[startY][startX] == State::wall)
		for (int i = 0; i < aroundPointsSize; i += 2) {
			if (matrix[startY + aroundPoints[i]][startX + aroundPoints[i + 1]] == State::interior) {
				startY += aroundPoints[i];
				startX += aroundPoints[i + 1];
				break;
			}
		}
	massert(matrix[startY][startX] == State::interior);

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
		data[dataPos] = static_cast<float>(th.snd);
		data[dataPos + 1] = static_cast<float>(th.fst);
		dataPos += vertSize;

		for (int i = 0, iend = (withWalls ? aroundPointsSize : aroundPointsSizeShort); i < iend; i += 2) {
			int const newY = th.fst + aroundPoints[i];
			int const newX = th.snd + aroundPoints[i + 1];
			if (insideMatrix(newX, newY)) {
				if (matrix[newY][newX] == State::interior && i < aroundPointsSizeShort) {
					queue.push({ newY, newX });
					nonConstThis->matrix[newY][newX] = State::markedInterior;
				}
				else if (withWalls && matrix[newY][newX] == State::wall && (i < aroundPointsSizeShort || aroundBorder(newX, newY))) {
					data[dataPos] = static_cast<float>(newX);
					data[dataPos + 1] = static_cast<float>(newY);
					dataPos += vertSize;

					nonConstThis->matrix[newY][newX] = State::markedWall;
				}
			}
		}

		if (--amountOfPointsLeftOnTheCurrentInterval == 0) {
			amountOfPointsLeftOnTheCurrentInterval = static_cast<int>(queue.size());
			intervals.emplace_back(dataPos / vertSize);
		}
	}
	massert(amountOfPointsLeftOnTheCurrentInterval == 0);
	massert(dataPos == data.size());
	intervals.emplace_back(dataPos / vertSize);

	for (auto & x : nonConstThis->matrix)
		for (auto & t : x)
			if (t == State::markedInterior)
				t = State::interior;
			else if (t == State::markedWall)
				t = State::wall;
}

void MazeGenerator::binaryTreeGenerator(int const width, int const height) {
	const int xend = width - !(width & 1);
	const int yend = height - !(height & 1);

	for (int x = 0; x < xend; ++x)
		matrix[0][x] = State::interior;

	for (int y = 1; y < yend; ++y)
		matrix[y][xend - 1] = State::interior;

	for (int y = 2; y < height; y += 2)
		for (int x = 0; x < width - 2; x += 2) {
			matrix[y][x] = State::interior;
			if (randomGenerator() & 1)
				matrix[y - 1][x] = State::interior;
			else
				matrix[y][x + 1] = State::interior;
		}
}

void MazeGenerator::sidewinderGenerator(int width, int height) {
	for (int x = 0, xend = width - !(width & 1); x < xend; ++x)
		matrix[0][x] = State::interior;

	for (int y = 2; y < height; y += 2) {
		int leftOnTheCurrentY = (width + 1) >> 1;
		int x = 0;
		while (leftOnTheCurrentY > 0) {
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
}

void MazeGenerator::primGenerator(int startX, int startY) {
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
}

void MazeGenerator::kruskalGenerator(int width, int height) {
	std::vector<Pair<int, int> > walls;

	matrix[0][0] = State::interior;
	for (int x = 2; x < width; x += 2) {
		matrix[0][x] = State::interior;
		walls.emplace_back(0, x - 1);
	}
	for (int y = 2; y < height; y += 2) {
		matrix[y][0] = State::interior;
		walls.emplace_back(y - 1, 0);
	}
	for (int y = 2; y < height; y += 2)
		for (int x = 2; x < width; x += 2) {
			matrix[y][x] = State::interior;
			walls.emplace_back(y, x - 1);
			walls.emplace_back(y - 1, x);
		}

	randomShuffle(walls);

	auto linearNumber = [rowSize = (width + 1) >> 1](int y, int x) {return (y >> 1) * rowSize + (x >> 1); };
	DSU dsu(((width + 1) >> 1) * ((height + 1) >> 1));

	for (auto & el : walls) {
		int first, second;
		if (el.fst & 1) {
			// vertical connection
			first = dsu.find(linearNumber(el.fst - 1, el.snd));
			second = dsu.find(linearNumber(el.fst + 1, el.snd));
		}
		else {
			// horizontal connection
			first = dsu.find(linearNumber(el.fst, el.snd - 1));
			second = dsu.find(linearNumber(el.fst, el.snd + 1));
		}
		if (first != second) {
			dsu.merge(first, second);
			matrix[el.fst][el.snd] = State::interior;
		}
	}
}

void MazeGenerator::recursiveBacktrackerGenerator() {
	using Point = Pair<int, int>; // {y, x}
	using Directions = std::array<Point, 4>;
	using Data = Triple<int, Point, Directions >;

	auto getRandomDirections = [this]() {
		Directions directions{ { { 2, 0 }, { 0, 2 }, { -2, 0 }, { 0, -2 } } };
		randomShuffle(directions);
		return directions;
	};

	auto recursiveFunction = [this, &getRandomDirections](Data & data) -> std::optional<Data> {
		auto & iterationCounter = data.fst;
		auto & directions = data.trd;
		if (iterationCounter == directions.size())
			return std::optional<Data>();

		auto[posY, posX] = data.snd;
		if (iterationCounter == 0) matrix[posY][posX] = State::interior;

		for (; iterationCounter != directions.size(); ++iterationCounter) {
			auto const & dir = directions[iterationCounter];
			Point newCell = { posY + dir.fst , posX + dir.snd };
			if (insideMatrix(newCell.snd, newCell.fst) && matrix[newCell.fst][newCell.snd] == State::wall)
				break;
		};

		if (iterationCounter == directions.size())
			return std::optional<Data>();

		auto const & dir = directions[iterationCounter];
		matrix[posY + (dir.fst >> 1)][posX + (dir.snd >> 1)] = State::interior; // remove wall

		return Data(0, { posY + dir.fst , posX + dir.snd }, getRandomDirections());
	};

	SystemHeapStack<Data> shs(std::move(recursiveFunction));
	shs.call(Data(0, { 0, 0 }, getRandomDirections()));
}

void MazeGenerator::recursiveDivisionGenerator(int width, int height) {
	width -= !(width & 1);
	height -= !(height & 1);
	for (int y = 0; y < height; y += 2)
		for (int x = 0; x < width; x += 2)
			matrix[y][x] = State::interior;

	std::function<void(int, int, int, int)> func;
	func = [this, &func](int shiftX, int shiftY, int w, int h) {
		if (w == 1) {
			for (int y = shiftY + 1; y < h + shiftY; y += 2)
				matrix[y][shiftX] = State::interior;
			return;
		}
		if (h == 1) {
			for (int x = shiftX + 1; x < w + shiftX; x += 2)
				matrix[shiftY][x] = State::interior;
			return;
		}
		if ((randomGenerator() % (w + h)) < static_cast<unsigned int>(w)) {
			// vertical division
			int posX = 1 + ((randomGenerator() % (w >> 1)) << 1) + shiftX;
			int posY = ((randomGenerator() % ((h + 1) >> 1)) << 1) + shiftY;
			matrix[posY][posX] = State::interior;
			func(shiftX, shiftY, posX - shiftX, h);
			func(posX + 1, shiftY, w - posX + shiftX - 1, h);
		}
		else {
			// horisontal division
			int posY = 1 + ((randomGenerator() % (h >> 1)) << 1) + shiftY;
			int posX = ((randomGenerator() % ((w + 1) >> 1)) << 1) + shiftX;
			matrix[posY][posX] = State::interior;
			func(shiftX, shiftY, w, posY - shiftY);
			func(shiftX, posY + 1, w, h - posY + shiftY - 1);
		}
	};

	func(0, 0, width, height);
}

void MazeGenerator::huntAndKillGenerator(int width, int height) {
	width -= !(width & 1);
	height -= !(height & 1);

	using Point = Pair<int, int>; // {y, x}
	using Directions = std::array<Point, 4>;

	constexpr Directions directions{ { { 2, 0 }, { 0, 2 }, { -2, 0 }, { 0, -2 } } };

	std::vector<int> rows((height + 1) / 2);
	std::vector<int> cols((width + 1) / 2);
	for (int i = 0; i < rows.size(); ++i) rows[i] = i << 1;
	for (int i = 0; i < cols.size(); ++i) cols[i] = i << 1;
	randomShuffle(cols);

	auto hunt = [this, width, height, &directions, &rows, &cols]() mutable->std::optional<Point> {
		randomShuffle(rows);
		for (int i = 0; i < rows.size(); ) {
			bool allInteriors = true;
			int y = rows[i];
			for (auto x : cols) {
				if (matrix[y][x] == State::interior) continue;
				allInteriors = false;
				for (auto & t : directions) {
					auto const newX = x + t.snd;
					auto const newY = y + t.fst;
					if (insideMatrix(newX, newY) && matrix[newY][newX] == State::interior)
						return Point(y, x);
				}
			}
			if (allInteriors) {
				rows[i] = rows.back();
				rows.pop_back();
			}
			else
				++i;
		}
		return std::optional<Point>();
	};

	std::vector<int> possibleDirection;
	possibleDirection.reserve(4);
	auto updateCorrectDirects = [this, &possibleDirection, &directions](int x, int y, State state) {
		possibleDirection.clear();
		for (int i = 0; i < directions.size(); ++i) {
			auto const newX = x + directions[i].snd;
			auto const newY = y + directions[i].fst;
			if (insideMatrix(newX, newY) && matrix[newY][newX] == state)
				possibleDirection.push_back(i);
		}
	};

	int x = 0, y = 0;
	while (true) {
		matrix[y][x] = State::interior;
		updateCorrectDirects(x, y, State::wall);

		bool hasInteriorAround = !possibleDirection.empty();

		if (!hasInteriorAround) {
			auto targer = hunt();
			if (!targer.has_value()) break; // maze completed
			y = targer.value().fst;
			x = targer.value().snd;
			updateCorrectDirects(x, y, State::interior);
		}

		auto const & dir = directions[possibleDirection[(possibleDirection.size() == 1 ? 0 : randomGenerator() % possibleDirection.size())]];
		matrix[y + (dir.fst >> 1)][x + (dir.snd >> 1)] = State::interior; // remove wall
		if (hasInteriorAround) {
			x += dir.snd;
			y += dir.fst;
		}
	}

}

void MazeGenerator::ellerGenerator(int width, int height) {
	width -= !(width & 1);
	height -= !(height & 1);

	const int rowSize = (width + 1) >> 1;
	DSU sets(rowSize);
	for (int y = 0; y < height - 2; y += 2) {
		DSU newSets(rowSize);
		std::vector<int> mapper(rowSize, -1); // [root of last set] -> {eny element of new set, which has interior from downside}
		for (int i = 0; i < rowSize - 1; ++i) {
			auto leftSet = sets.find(i);
			auto rightSet = sets.find(i + 1);
			if (leftSet != rightSet && (randomGenerator() & 1)) {
				matrix[y][(i << 1) + 1] = State::interior; // remove wall
				sets.merge(leftSet, rightSet);
			}
		}

		for (int i = 0; i < rowSize; ++i)
			if (randomGenerator() & 1) {
				matrix[y + 1][i << 1] = State::interior;
				auto & el = mapper[sets.find(i)];
				if (el != -1)
					newSets.merge(i, el);
				el = i;
			}

		for (int i = 0; i < rowSize; ++i) {
			matrix[y][i << 1] = State::interior;
			auto &el = mapper[sets.find(i)];
			if (el == -1) {
				matrix[y + 1][i << 1] = State::interior;
				el = i;
			}
		}

		sets = std::move(newSets);
	}

	for (int i = 0; i < rowSize - 1; ++i) {
		matrix[height - 1][i << 1] = State::interior;
		auto leftSet = sets.find(i);
		auto rightSet = sets.find(i + 1);
		if (leftSet != rightSet) {
			matrix[height - 1][(i << 1) + 1] = State::interior; // remove wall
			sets.merge(leftSet, rightSet);
		}
	}
	matrix[height - 1][width - 1] = State::interior;
}