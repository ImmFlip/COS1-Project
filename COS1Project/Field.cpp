#include "Field.h"
#include <iostream>

Field::Field(difficulty d) {
	switch (d) {
	case easy:
		width = 9;
		height = 9;
		numTiles = 81;
		bombs = 10;
		break;
	case medium:
		width = 16;
		height = 16;
		numTiles = 256;
		bombs = 40;
		break;
	case hard:
		width = 16;
		height = 24;
		numTiles = 384;
		bombs = 70;
		break;
	}
	fillField(numTiles);
}

void Field::fillField(int tiles) {
	map.clear();
	for (int i = 0; i < tiles; i++) {
		Tile t;
		map.push_back(t);
	}
	for (int i = 0; i < bombs; i++) {
		bool converted = false;
		while (!converted) {
			int l = std::rand() % static_cast<int>(map.size());

			if (!map[l].getBomb()) {
				map[l].hasBomb();
				converted = true;
			}
		}
	}
}

int Field::countAdjacentBombs(int row, int col) {
	int count = 0;

	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {

			if (r < 0 || r >= height || c < 0 || c >= width) {
				continue;
			}

			int index = r * width + c;

			if (map[index].getBomb()) {
				count++;
			}
		}
	}
	return count;
}

void Field::revealRecursive(int row, int col) {
	if (row < 0 || row >= height || col < 0 || col >= width) {
		return;
	}

	int index = row * width + col;

	if (map[index].isRevealed() || map[index].getBomb()) {
		return;
	}

	map[index].reveal();
	int count = countAdjacentBombs(row, col);
	map[index].setAdjacentBombs(count);

	if (count == 0) {
		for (int r = row - 1; r <= row + 1; r++) {
			for (int c = col - 1; c <= col + 1; c++) {

				if (r == row && c == col) {
					continue;
				}

				revealRecursive(r, c);
			}
		}
	}
}

bool Field::revealTile(int row, int col) {
	int index = row * width + col;

	if (map[index].getBomb()) {
		map[index].reveal();
		return false;
	}

	revealRecursive(row, col);
	return true;
}

void Field::revealAll() {
	for (int i = 0; i < numTiles; i++) {
		map[i].reveal();

		if (!map[i].getBomb()) {
			int row = i / width;
			int col = i % width;

			map[i].setAdjacentBombs(countAdjacentBombs(row, col));
		}
	}
}

bool Field::hasWon() const {
	for (const Tile& t : map) {
		if (!t.getBomb() && !t.isRevealed()) {
			return false;
		}
	}

	return true;
}

void Field::printField() {
	std::cout << "\n   ";

	for (int c = 0; c < width; c++) {
		std::cout << c + 1 << " ";
	}

	std::cout << "\n";

	for (int r = 0; r < height; r++) {
		if (r + 1 < 10) {
			std::cout << " ";
		}
		std::cout << r + 1 << " ";

		for (int c = 0; c < width; c++) {
			int index = r * width + c;

			if (!map[index].isRevealed()) {
				std::cout << "# ";
			}
			else if (map[index].getBomb()) {
				std::cout << "* ";
			}
			else {
				int count = map[index].getAdjacentBombs();

				if (count == 0) {
					std::cout << ". ";
				}
				else {
					std::cout << count << " ";
				}
			}
		}

		std::cout << "\n";
	}
	std::cout << std::endl;
}