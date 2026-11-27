#pragma once
#include <vector>
#include "Tile.h"

class Field {
private:
	std::vector<Tile> map;
	int bombs;
	int numTiles;
	int width;
	int height;

	int countAdjacentBombs(int r, int c);
	void revealRecursive(int r, int c);
public:
	enum difficulty {
		easy,
		medium,
		hard
	};

	Field(difficulty d);

	void printField();
	void fillField(int tiles);

	bool revealTile(int r, int c);
	void revealAll();
	bool hasWon() const;
	int getWidth() const { return width; }
	int getHeight() const { return height; }
};

