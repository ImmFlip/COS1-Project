#include "Player.h"
#include <iostream>

void Player::displayPlayer() {
	std::cout << "\nName:\t" << name << std::endl;
	std::cout << "Wins:\t" << wins << std::endl;
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