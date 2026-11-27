#pragma once
#include <string>
#include <cstring>

class Player {
private:
	std::string name;
	int wins;
	int winStreak;
	int totalGames;
public:
	Player() : name(""), wins(0), winStreak(0), totalGames(0) {}
	Player(std::string n) : name(n), wins(0), winStreak(0), totalGames(0) {}
	Player(std::string n, int w, int ws, int g) : name(n), wins(w), winStreak(ws), totalGames(g) {}

	void displayPlayer();
	void setStreak(bool win);
	void increment(bool win);

	Player& operator=(Player& other);
	Player(Player& other);
};

