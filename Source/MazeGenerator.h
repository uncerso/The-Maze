#pragma once
#include <vector>
#include <random>
#include "PointsToDraw.h"

class MazeGenerator {
public:
	enum class MazeType { binaryTree, sidewinder, prime, kruskal, recursiveBacktracker, recursiveDivision, huntAndKill, eller };
	enum class DrawType { oneFrame, wave, withWalls };

	MazeGenerator();
	~MazeGenerator() = default;

	void generate(unsigned int seed, int width, int height, MazeType mazeType);

	PointsToDraw getMazeAsPointsToDraw(DrawType drawType, int startX = 0, int startY = 0) const;

#ifndef NDEBUG
	void dump() const;
#endif

private:
	enum class State { wall, interior, markedWall, markedInterior };

	unsigned int lastSeed;
	int lastWidth;
	int lastHeight;
	int amountOfInteriors;
	MazeType lastMazeType;
	std::mt19937 randomGenerator;
	std::vector<std::vector<State> > matrix;

	void fillMatrix(State state = State::wall) noexcept;
	bool insideMatrix(int x, int y) const noexcept;

	template <class T>
	void randomShuffle(T & v);

	void resizeMatrix(int width, int height);

	void oneFramePainting(std::vector<float> & data, std::vector<int> & intervals) const;
	void wavePainting(int startX, int startY, std::vector<float> & data, std::vector<int> & intervals, bool withWalls) const;

	void evenEdgeFiller(int width, int height);
	int calculateAmountOfInteriors(int width, int height) const noexcept;

	void binaryTreeGenerator(int width, int height);
	void sidewinderGenerator(int width, int height);
	void primGenerator(int startX, int startY);
	void kruskalGenerator(int width, int height);
	void recursiveBacktrackerGenerator();
	void recursiveDivisionGenerator(int width, int height);
	void huntAndKillGenerator(int width, int height);
	void ellerGenerator(int width, int height);
};

template<class T>
inline void MazeGenerator::randomShuffle(T & v) {
	for (int i = static_cast<int>(v.size()); i > 1; --i)
		std::swap(v[i - 1], v[randomGenerator() % i]);
}
