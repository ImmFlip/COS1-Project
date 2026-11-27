#include <iostream>
#include "Player.h"
#include "Field.h"

Player* player = nullptr;

void PlayGame(int dif) {
    Field::difficulty d;
    switch (dif) {
    case 1:
        d = Field::easy;
        break;
    case 2:
        d = Field::medium;
        break;
    case 3:
        d = Field::hard;
        break;
    }

    Field game(d);

    bool gameOver = false;

    while (!gameOver && !game.hasWon()) {
        game.printField();

        int row;
        int col;

        std::cout << "Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> col;

        row--;
        col--;

        if (row < 0 || row >= game.getWidth() || col < 0 || col >= game.getHeight()) {
            std::cout << "Invalid position! Try again.\n";
            continue;
        }

        if (!game.revealTile(row, col)) {
            std::cout << "\nBOOM! You hit a bomb!\n";
            gameOver = true;
        }
    }

    bool won = !gameOver && game.hasWon();

    game.revealAll();
    game.printField();

    if (won) {
        std::cout << "\nCongrats! You won!\n";
        player->increment(true);
        player->setStreak(true);
    }
    else {
        std::cout << "\nGame Over!\n";
        player->increment(false);
        player->setStreak(false);
    }
}

void PlayerMenu() {

    //Setup file Input later
    //For now just creates a default character
    
    int menuchoice = 0;
    bool valid = false;
    while (!valid) {
        std::cout << "\nPlease select an option\n";
        std::cout << "1. Load Player\n";
        std::cout << "2. Create New Player\n";
        std::cout << "What would you like to do: ";
        std::cin >> menuchoice;
        switch (menuchoice) {
        case 1:
            std::cout << "\nLoad player selected not implemented yet\n";
            break;
        case 2:
            std::cout << "\nCreate player selected not fully implemented yet\n";
            std::cout << "Creating defualt!\n" << std::endl;
            player = new Player("Default");
            valid = true;
            break;
        default:
            std::cout << "\nPlease enter a valid option!\n";
            break;
        }
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int menuchoice = 0;
    while (menuchoice != 4) {
        std::cin.clear();
        std::cout << "\tMINESWEEPER\n";
        std::cout << "1. New Game\n";
        std::cout << "2. Player Selection\n";
        std::cout << "3. View Stats\n";
        std::cout << "4. Exit\n";
        std::cout << "What would you like to do: ";
        std::cin >> menuchoice;
        switch (menuchoice) {
        case 1: {
            int dif = 0;
            bool valid = false;

            while (!valid) {
                std::cout << "\nSelect a difficulty\n";
                std::cout << "1. Easy\n";
                std::cout << "2. Medium\n";                 //Game selection menu
                std::cout << "3. Hard\n";
                std::cout << "4. Return to Menu\n";
                std::cout << "Choice: ";
                std::cin >> dif;

                switch (dif) {
                case 1: 
                    PlayGame(dif);
                    valid = true;
                    break;
                case 2:
                    PlayGame(dif);
                    valid = true;
                    break;
                case 3:
                    PlayGame(dif);
                    valid = true;
                    break;
                case 4:
                    valid = true;
                    break;
                default:
                    std::cout << "\nError! Please enter valid option!\n";
                    break;
                }
                }
                break;
            }
        case 2:
            PlayerMenu();
            break;
        case 3:
            std::cout << "\nStats selected\n";
            player->displayPlayer();
            break;
        case 4:
            delete player;
            break;
        }
    }
    return 0;
}