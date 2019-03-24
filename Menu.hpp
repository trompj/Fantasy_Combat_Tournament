/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: Menu functions for fantasy combat game simulation.
 * startMenu - Presents start menu to user, asking if user would like to start fantasy combat game or exit.
 * User input is validated and returned as integer value to calling function.
 * endMenu - Present end menu to user, asking if user would like to continue playing game or exit. User input
 * is validated and returned as integer value to calling function.
*/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "inputValidation.hpp"

//Presents start menu to user asking if user would like to start fantasy combat game
int startMenu();

//Ask user if they would like to keep playing. If user elects option 2 to quit, exit
//game. If user elects option 1, restart game.
int endMenu();

//Prompts user to enter number of fighters for team and calls validation function to accept/validate
//input from user. Accepts int parameter for team number.
int teamMenu(int);

//Prompt user if they would like to display losers pile on screen. Return boolean value if user selects
//to print contents of pile.
bool losersPrint();

//Output/prompt option to display reduced attack/defense data or full roll data during play. Return integer
//value for menu selection.
int attackMenuOptions();

#endif //MENU_HPP
