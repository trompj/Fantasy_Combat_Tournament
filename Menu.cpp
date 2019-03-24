/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: Menu functions for fantasy combat game simulation.
 * startMenu - Presents start menu to user, asking if user would like to start fantasy combat game or exit.
 * User input is validated and returned as integer value to calling function.
 * endMenu - Present end menu to user, asking if user would like to continue playing game or exit. User input
 * is validated and returned as integer value to calling function.
*/

#include "Menu.hpp"

//Presents start menu to user asking if user would like to start fantasy combat game
int startMenu() {
    //Output menu options and prompt user for input
    std::cout << "Welcome to Fantasy Combat!" << std::endl;
    std::cout << "Please select from the options below: " << std::endl;
    std::cout << "1. Start Fantasy Combat" << std::endl;
    std::cout << "2. Exit" << std::endl;

    int menuSelection = 0;

    //Set menu selection after validation of integer input
    menuSelection = validateInputRangeInt(1, 2);

    return menuSelection;
}

//Ask user if they would like to keep playing. If user elects option 2 to quit, exit
//game. If user elects option 1, restart game.
int endMenu() {
    //Output menu options and prompt user for input
    std::cout << "Round Complete! Would you like to keep playing?" << std::endl;
    std::cout << "Please select from the options below: " << std::endl;
    std::cout << "1. Play Fantasy Combat Again" << std::endl;
    std::cout << "2. Exit" << std::endl;

    int menuSelection = 0;

    //Set menu selection after validation of integer input
    menuSelection = validateInputRangeInt(1, 2);

    return menuSelection;
}

//Prompts user to enter number of fighters for team and calls validation function to accept/validate
//input from user. Accepts int parameter for team number.
int teamMenu(int teamNumber) {
    //Output menu options and prompt user for input
    std::cout << "How many fighters would you like team #" << teamNumber << " to have?" << std::endl;
    std::cout << "Please enter a valid positive integer value from 1 through 20." << std::endl;

    int teamSize = 0;

    //Set team size after validation of integer input.
    teamSize = validateInputRangeInt(1, 20);

    return teamSize;
}

//Prompt user if they would like to display losers pile on screen. Return boolean value if user selects
//to print contents of pile.
bool losersPrint() {
    bool displayLosers = false;
    int menuSelection = 0;

    //Prompt user for menu selection to display losing fighters.
    std::cout << "Would you like to display the losing fighters of the tournament? " << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    //Validate selection
    menuSelection = validateInputRangeInt(1, 2);

    //If user selected to print losers, set displayLosers to true and return value to calling function.
    if (menuSelection == 1) {
        displayLosers = true;
    }

    std::cout << std::endl;

    return displayLosers;
}

//Output/prompt option to display reduced attack/defense data or full roll data during play. Return integer
//value for menu selection.
int attackMenuOptions() {
    int menuSelection = 0;

    //Prompt user for menu selection to display full or reduced attack/defense output.
    std::cout << "Would you like to display all battle data (roll values for attack/defense)? " << std::endl;
    std::cout << "1. Simple Output" << std::endl;
    std::cout << "2. Complete/Complex Output" << std::endl;

    menuSelection = validateInputRangeInt(1, 2);

    return menuSelection;
}