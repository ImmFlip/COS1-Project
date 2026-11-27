#include "Player.h"
#include <iostream>

void Player::displayPlayer() {
	std::cout << "\nName:\t\t" << name << std::endl;
	std::cout << "Wins:\t\t" << wins << std::endl;
	std::cout << "Win Streak:\t" << winStreak << std::endl;
	std::cout << "Total Games:\t" << totalGames << std::endl;
	std::cout << std::endl;
}

void Player::setStreak(bool win) {
	if (win) {
		winStreak++;
	}
	else if (!win) {
		winStreak = 0;
	}
}

void Player::increment(bool win) {
	totalGames++;
	if (win) {
		wins++;
	}
}

Player& Player::operator=(Player& other) {
	if (this != &other) {
		name = other.name;
		wins = other.wins;
		winStreak = other.winStreak;
		totalGames = other.totalGames;
	}
	return *this;
}

Player::Player(Player& other) {
	name = other.name;
	wins = other.wins;
	winStreak = other.winStreak;
	totalGames = other.totalGames;
}