#pragma once

class Tile {
private:
	bool bomb;
	bool revealed;
	int adjacentBombs;
public:
	Tile() : bomb(false), revealed(false), adjacentBombs(0) {}
	void hasBomb() { bomb = true; }
	bool getBomb() const { return bomb; }
	void reveal() { revealed = true; }
	bool isRevealed() const { return revealed; }
	void setAdjacentBombs(int count) { adjacentBombs = count; }
	int getAdjacentBombs() const { return adjacentBombs; }
};

