#pragma once
#include <vector>
#include "Tile.h"

class Field {
private:
	enum difficulty {
		easy,
		medium,
		hard
	};
	std::vector<Tile> map;
	int bombs;
	int numTiles;
public:
	Field(difficulty d);

	void printField();
	void fillField(int tiles);
};

