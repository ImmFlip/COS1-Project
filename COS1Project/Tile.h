#pragma once

class Tile {
private:
	bool bomb;
public:
	Tile() : bomb(false) {}
	void hasBomb() { bomb = true; }
	bool getBomb() const { return bomb; }
};

