

#ifndef FANTASYGAME_HPP
#define FANTASYGAME_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "Queue.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "BlueMen.hpp"


class FantasyGame {
private:
    Queue combatTeam_1;
    Queue combatTeam_2;
    Queue loserQueue;

    int tournamentRound = 0;
    int teamOneScore = 0;
    int teamTwoScore = 0;

    //Display tournament results on screen to user. Function called when one team has no fighters left.
    void printTournamentResults();

    //Display losers pile on screen to user.
    void printLosersPile();

    //Presents play menu: Displays all character types by name to user and prompts user to
    //select character type to add to team. Takes int values for team number and fighter number as
    //parameters. Returns Character pointer to calling function for newly created Character.
    Character* characterMenu(int, int);

    //Requests name input from user for character if user would like to name them. Otherwise, returns
    //a generic character name.
    std::string characterName(Queue*, std::string);

public:
    //Constructor sets head to nullptr for empty queue at queue creation.
    FantasyGame();

    //Destructor to free all allocated memory
    ~FantasyGame();

    //Runs fantasy combat game and brings together functionality
    void gameRun();

    //Print out attack/defense information
    void displayFullAttack();

    //Print out attack/defense information
    void displaySimpleAttack();

    //Print out battle/win information at end of each battle. Takes integer value as parameter for
    //amount of damage inflicted on winning fighter as well as pointer to pointer of team queue
    //head of winning team.
    void displayBattleWin(int, Queue*);

};


#endif //FANTASYGAME_HPP
