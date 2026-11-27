#include <iostream>
#include "Player.h"
#include "Field.h"

Player* player = nullptr;

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
    int menuchoice = 0;
    while (menuchoice != 4) {
        std::cout << "\tMINESWEEPER\n";
        std::cout << "1. New Game\n";
        std::cout << "2. Player Selection\n";
        std::cout << "3. View Stats\n";
        std::cout << "4. Exit\n";
        std::cout << "What would you like to do: ";
        std::cin >> menuchoice;
        switch (menuchoice) {
        case 1:
            std::cout << "\nNew game selected\n" << std::endl;
            break;
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