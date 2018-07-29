#pragma once
#include <vector>
#include <random>
#include "PointsToDraw.h"

class MazeGenerator {
public:
	enum class MazeType { binaryTree, sidewinder, noname };
	enum class DrawType { oneFrame, wave, withWalls };

	MazeGenerator();
	~MazeGenerator() = default;

	void generate(int seed, int width, int height, MazeType mazeType);

	PointsToDraw getMazeAsPointsToDraw(DrawType drawType, int startX = 0, int startY = 0) const;

private:
	enum class State { wall, interior, markedWall, markedInterior};

	int lastSeed;
	int lastWidth;
	int lastHeight;
	int amountOfInteriors;
	MazeType lastMazeType;
	std::mt19937 randomGenerator;
	std::vector<std::vector<State> > matrix;

	void fillMatrix(State state = State::wall) noexcept;
	bool insideMatrix(int x, int y) const noexcept;

	void resizeMatrix(int width, int height);

	void oneFramePainting(std::vector<float> & data, std::vector<int> & intervals) const;
	void wavePainting(int startX, int startY, std::vector<float> & data, std::vector<int> & intervals, bool withWalls) const;

	int evenEdgeFiller(int width, int height);

	int binaryTreeGenerator(int width, int height);
	int sidewinderGenerator(int width, int height, int maxBlockSize);
	int nonameGenerator(int width, int height, int startX, int startY);
};