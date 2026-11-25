#include "Field.h"

Field::Field(difficulty d) {
	switch (d) {
	case easy:
		numTiles = 81;
		bombs = 10;
		fillField(numTiles);
		break;
	case medium:
		numTiles = 256;
		bombs = 40;
		fillField(numTiles);
		break;
	case hard:
		numTiles = 384;
		bombs = 70;
		fillField(numTiles);
		break;
	}
}

void Field::fillField(int tiles) {
	for (int i = 0; i < tiles; i++) {
		Tile t;
		map.push_back(t);
	}
	for (int i = 0; i < bombs; i++) {
		bool converted = false;
		while (!converted) {
			int l = (std::rand() % map.size()) - 1;
			if (map[l].getBomb() == false) {
				map[l].hasBomb();
				converted = true;
			}
		}
	}
}