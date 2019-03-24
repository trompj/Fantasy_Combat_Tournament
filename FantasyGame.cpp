/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/16/2019
 * Description:
 * Class Variable:
 * Class Functions:
*/

#include "FantasyGame.hpp"

//Default constructor sets head to nullptr for empty queue.
FantasyGame::FantasyGame() {}

//Destructor to free all allocated memory - Queue class frees Character* and QueueNode memory.
FantasyGame::~FantasyGame() {}

//Runs fantasy combat game and brings together functionality. Controls menu functions and attack/display functions
//over course of tournament.
void FantasyGame::gameRun() {
    int menuSelection = 0;

    //Start menu for user to select to play or quit
    menuSelection = startMenu();

    while (menuSelection != 2) {
        //1 for simple output, 2 for complex output
        int battleOutputSelection = 0;

        battleOutputSelection = attackMenuOptions();

        int teamOneSize = 0, teamTwoSize = 0;
        //Request team size from user for team #1
        teamOneSize = teamMenu(1);

        //Request team size from user for team #2
        teamTwoSize = teamMenu(2);

        //Set characters/fighters for team #1
        for (int count = 0; count < teamOneSize; count++) {
            Character* newCharacter;
            newCharacter = characterMenu(1, (count + 1));
            combatTeam_1.addCharBack(newCharacter);
        }

        //Set characters/fighters for team #2
        for (int count = 0; count < teamTwoSize; count++) {
            Character* newCharacter;
            newCharacter = characterMenu(2, (count + 1));
            combatTeam_2.addCharBack(newCharacter);
        }

        //Perform attacks between first members of each team until one team loses.
        do {
            //If user elects to display all output, displayFullAttack.
            if (battleOutputSelection == 2) {
                //Display full attack/defense with rolls between two characters until death
                displayFullAttack();
            }
            //Simple output displayed.
            else {
                //Display basic win/loss at end of each battle. No roll output.
                displaySimpleAttack();
            }
        } while (!combatTeam_1.isEmpty() && !combatTeam_2.isEmpty());

        //Print end of tournament results to user.
        printTournamentResults();

        //Allow user to choose to print out contents of losers container
        printLosersPile();

        //End menu allows user to select to play again or quit
        menuSelection = endMenu();

        //If user elects to restart game, all queues are wiped clean
        if (menuSelection == 1) {
            //Loop through list and free allocated memory for nodes until losers queue is empty.
            while (!loserQueue.isEmpty()) {
                loserQueue.deleteFront();
            }
            //Loop through list and free allocated memory for nodes until team 1 queue is empty.
            while (!combatTeam_1.isEmpty()) {
                combatTeam_1.deleteFront();
            }
            //Loop through list and free allocated memory for nodes until team 2 queue is empty.
            while (!combatTeam_2.isEmpty()) {
                combatTeam_2.deleteFront();
            }
            //Reset round and scores
            tournamentRound = 0;
            teamOneScore = 0;
            teamTwoScore = 0;
        }
    }
}

//Requests name input from user for character if user would like to name them. Otherwise, returns
//a generic character name. Takes parameter for team queue and string value for character type.
//Function returns string value for name of character.
std::string FantasyGame::characterName(Queue* inputQueue, std::string inputCharType) {
    int menuSelection = 0;
    std::string inputName = "";

    std::cout << "Would you like to name your character? Default character name will be in the form of" << std::endl;
    std::cout << "'Barbarian No. 1' with the integer value corresponding to the number of that character type on" << std::endl;
    std::cout << "the team at time of creation." << std::endl;
    std::cout << "Choose an integer option below." << std::endl;
    std::cout << "1. Name character" << std::endl;
    std::cout << "2. Use default character name" << std::endl;
    menuSelection = validateInputRangeInt(1, 2);

    //If menu selection is 1, allow user to name character.
    if (menuSelection == 1) {
        std::cout << std::endl;
        std::cout << "What would you like the name of your fighter to be? ";
        getline(std::cin, inputName);
    }

    //Else, create generic character name based on number of characters present in team of that type.
    else {
        inputName = inputCharType + " No. " + std::to_string(inputQueue->numCharTeam(inputCharType));
    }

    std::cout << std::endl;

    return inputName;
}

//Presents play menu: Displays all character types by name to user and prompts user to
//select character type to add to team. Takes int values for team number and fighter number as
//parameters. Returns Character pointer to calling function for newly created Character.
Character* FantasyGame::characterMenu(int inputTeamNum, int inputFighterNum) {
    //Output team number and fighter number that user is selecting for.
    std::cout << "Team Number: " << inputTeamNum << "  Fighter Number: " << inputFighterNum
              << std::endl << std::endl;

    //Output character options to user for selection
    std::cout << "CHARACTER OPTIONS" << std::endl;
    std::cout << "Vampire" << std::endl;
    std::cout << "Barbarian" << std::endl;
    std::cout << "Blue Men" << std::endl;
    std::cout << "Medusa" << std::endl;
    std::cout << "Harry Potter\n" << std::endl;
    std::cout << "Please select character to fight: ";

    bool characterChosen = false;
    Character* newCharacter = nullptr;
    //Loop until character is successfully chosen by user
    do {
        std::string userCharSelection = "";
        std::string userNameSelection = "";
        std::string teamSelection = "Team " + std::to_string(inputTeamNum);

        //Get user input
        getline(std::cin, userCharSelection);

        std::cout << std::endl;

        //Change string to uppercase for easier entry/comparison of strings by making
        //input less picky.
        userCharSelection = stringUpperCase(userCharSelection);

        //If barbarian is selected, add barbarian character to team queue.
        //Ask user for name of fighter.
        if (userCharSelection == "BARBARIAN") {
            if (inputTeamNum == 1) {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_1, "Barbarian");
            }
            else {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_2, "Barbarian");
            }
            //Add character/fighter to back of list
            newCharacter = new Barbarian(userNameSelection, teamSelection);
            characterChosen = true;
        }

        //If vampire is selected, add vampire character to team queue
        //Ask user for name of fighter.
        else if (userCharSelection == "VAMPIRE") {
            if (inputTeamNum == 1) {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_1, "Vampire");
            }
            else {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_2, "Vampire");
            }
            //Add character/fighter to back of list
            newCharacter = new Vampire(userNameSelection, teamSelection);
            characterChosen = true;
        }

        //If blue men is selected, add blue men character to team queue
        //Ask user for name of fighter.
        else if (userCharSelection == "BLUE MEN") {
            if (inputTeamNum == 1) {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_1, "Blue Men");
            }
            else {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_2, "Blue Men");
            }
            //Add character/fighter to back of list
            newCharacter = new BlueMen(userNameSelection, teamSelection);
            characterChosen = true;
        }

        //If medusa is selected, add medusa character to team queue
        //Ask user for name of fighter.
        else if (userCharSelection == "MEDUSA") {
            if (inputTeamNum == 1) {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_1, "Medusa");
            }
            else {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_2, "Medusa");
            }
            //Add character/fighter to back of list
            newCharacter = new Medusa(userNameSelection, teamSelection);
            characterChosen = true;
        }

        //If harry potter is selected, add harry potter character to team queue.
        //Ask user for name of fighter.
        else if (userCharSelection == "HARRY POTTER") {
            if (inputTeamNum == 1) {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_1, "Harry Potter");
            }
            else {
                //Determine character/fighter name
                userNameSelection = characterName(&combatTeam_2, "Harry Potter");
            }
            //Add character/fighter to back of list
            newCharacter = new HarryPotter(userNameSelection, teamSelection);
            characterChosen = true;
        }

        //If no character is added, re-prompt user for selection as incorrect selection was made
        if (!characterChosen) {
            std::cout << "An incorrect character selection was made. Please enter a character type from "
                         "the list above." << std::endl;
        }
    } while (!characterChosen);

    return newCharacter;
}

//Run attack and print out attack/defense information. Attack rounds are ran until one character dies.
void FantasyGame::displaySimpleAttack() {
    int roundCount = 1;
    int startingStrengthTeam_1 = combatTeam_1.getFront()->getStrength();
    int startingStrengthTeam_2 = combatTeam_2.getFront()->getStrength();
    tournamentRound++;

    //Loop through attack/defense of characters until one character dies (strength reaches 0)
    do {
        int attackValue = 0;
        int loopCount = 0;

        //Loop through one attack/defense round (each character attacks and defends once)
        do {
            //Team one attacks for first loop iteration and team 2 defends.
            if (loopCount == 0) {
                //First character selection attacks
                attackValue = combatTeam_1.getFront()->attack(1);

                //Second character selection defends
                combatTeam_2.getFront()->defense(attackValue, 1);
            }
                //Team two attacks for second loop iteration and team 1 defends.
            else {
                //First character selection attacks
                attackValue = combatTeam_2.getFront()->attack(1);

                //Second character selection defends
                combatTeam_1.getFront()->defense(attackValue, 1);
            }

            loopCount++;
        } while ((combatTeam_1.getFront()->getStrength() > 0 && combatTeam_2.getFront()->getStrength() > 0)
                 && loopCount < 2);

        //Increase round number value for user output during loop
        roundCount++;

    } while (combatTeam_1.getFront()->getStrength() > 0 && combatTeam_2.getFront()->getStrength() > 0);

    //If character from team 1 lost and reached 0 strength, remove from front of queue and place in losers queue.
    //Character from team 2 is rotated to back of teams queue for a later fight.
    if (combatTeam_1.getFront()->getStrength() == 0) {
        //Set strength lost to difference between starting strength and ending strength value.
        int strengthLost = abs(combatTeam_2.getFront()->getStrength() - startingStrengthTeam_2);

        //Add losing fighter to losers pile.
        loserQueue.addFront(combatTeam_1.removeFront());

        //Display end of battle information for user.
        displayBattleWin(strengthLost, &combatTeam_2);

        //Move winning fighter to back of team queue.
        combatTeam_2.addBack(combatTeam_2.removeFront());

        //Adjust team scores
        //+2 for winning team
        teamTwoScore += 2;

        //-1 for losing team
        teamOneScore -= 1;
    }

    //Character from team 2 lost and reached 0 strength. Remove from front of queue and place in losers queue.
    //Character from team 1 is rotated to back of their teams queue for a later fight.
    else {
        //Set strength lost to difference between starting strength and ending strength value.
        int strengthLost = abs(combatTeam_1.getFront()->getStrength() - startingStrengthTeam_1);

        //Add losing fighter to losers pile.
        loserQueue.addFront(combatTeam_2.removeFront());

        //Display end of battle information for user.
        displayBattleWin(strengthLost, &combatTeam_1);

        //Move winning fighter to back of team queue.
        combatTeam_1.addBack(combatTeam_1.removeFront());

        //Adjust team scores
        //+2 for winning team
        teamOneScore += 2;

        //-1 for losing team
        teamTwoScore -= 1;
    }
}

//Run attack and print out attack/defense information. Attack rounds are ran until one character dies.
void FantasyGame::displayFullAttack() {
    int roundCount = 1;
    int startingStrengthTeam_1 = combatTeam_1.getFront()->getStrength();
    int startingStrengthTeam_2 = combatTeam_2.getFront()->getStrength();
    tournamentRound++;

    //Loop through attack/defense of characters until one character dies (strength reaches 0)
    do {
        int attackValue = 0;

        std::cout << "ATTACK/DEFENSE ROUND " << roundCount << std::endl;

        int loopCount = 0;
        //Loop through one attack/defense round (each character attacks and defends once)
        do {
            //Team one attacks for first loop iteration and team 2 defends.
            if (loopCount == 0) {
                //Display attacker information to user
                std::cout << "Attacker: " << combatTeam_1.getFront()->getCharType() << std::endl << std::endl;

                //Display defenders information
                combatTeam_2.getFront()->displayDefenderInfo();

                //First character selection attacks
                attackValue = combatTeam_1.getFront()->attack(2);

                //Second character selection defends
                combatTeam_2.getFront()->defense(attackValue, 2);
            }
            //Team two attacks for second loop iteration and team 1 defends.
            else {
                //Display attacker information to user
                std::cout << "Attacker: " << combatTeam_2.getFront()->getCharType() << std::endl << std::endl;

                //Display defenders information
                combatTeam_1.getFront()->displayDefenderInfo();

                //First character selection attacks
                attackValue = combatTeam_2.getFront()->attack(2);

                //Second character selection defends
                combatTeam_1.getFront()->defense(attackValue, 2);
            }

            loopCount++;
        } while ((combatTeam_1.getFront()->getStrength() > 0 && combatTeam_2.getFront()->getStrength() > 0)
                 && loopCount < 2);

        //Increase round number value for user output during loop
        roundCount++;

    } while (combatTeam_1.getFront()->getStrength() > 0 && combatTeam_2.getFront()->getStrength() > 0);

    //If character from team 1 lost and reached 0 strength, remove from front of queue and place in losers queue.
    //Character from team 2 is rotated to back of teams queue for a later fight.
    if (combatTeam_1.getFront()->getStrength() == 0) {
        //Set strength lost to difference between starting strength and ending strength value.
        int strengthLost = abs(combatTeam_2.getFront()->getStrength() - startingStrengthTeam_2);

        //Add losing fighter to losers pile.
        loserQueue.addFront(combatTeam_1.removeFront());

        //Display end of battle information for user.
        displayBattleWin(strengthLost, &combatTeam_2);

        //Move winning fighter to back of team queue.
        combatTeam_2.addBack(combatTeam_2.removeFront());

        //Adjust team scores
        //+2 for winning team
        teamTwoScore += 2;

        //-1 for losing team
        teamOneScore -= 1;
    }

    //Character from team 2 lost and reached 0 strength. Remove from front of queue and place in losers queue.
    //Character from team 1 is rotated to back of their teams queue for a later fight.
    else {
        //Set strength lost to difference between starting strength and ending strength value.
        int strengthLost = abs(combatTeam_1.getFront()->getStrength() - startingStrengthTeam_1);

        //Add losing fighter to losers pile.
        loserQueue.addFront(combatTeam_2.removeFront());

        //Display end of battle information for user.
        displayBattleWin(strengthLost, &combatTeam_1);

        //Move winning fighter to back of team queue.
        combatTeam_1.addBack(combatTeam_1.removeFront());

        //Adjust team scores
        //+2 for winning team
        teamOneScore += 2;

        //-1 for losing team
        teamTwoScore -= 1;
    }
}

//Display tournament results on screen to user. Function called when one team has no fighters left.
void FantasyGame::printTournamentResults() {
    std::cout << "END OF TOURNAMENT" << std::endl;
    std::cout << "Team 1 Score: " << teamOneScore << std::endl;
    std::cout << "Team 2 Score: " << teamTwoScore << std::endl;

    //Team one won, output result to user.
    if (teamOneScore > teamTwoScore) {
        std::cout << "Team 1 has won the tournament!" << std::endl;
    }

    //Team two won, output result to user.
    else if (teamOneScore < teamTwoScore) {
        std::cout << "Team 2 has won the tournament!" << std::endl;
    }

    //Teams are tied, output result to user.
    else {
        std::cout << "Team 1 and team 2 are tied. The tournament has no winner." << std::endl;
    }
    std::cout << std::endl;
}

//Display losers pile on screen to user.
void FantasyGame::printLosersPile() {
    //Present option to print loser pile to user.
    if (losersPrint()) {
        std::cout << "TOURNAMENT LOSERS:" << std::endl;
        loserQueue.printQueue();
    }
}

//Print out battle/win information at end of each battle. Takes integer value as parameter for
//amount of damage inflicted on winning fighter as well as pointer to pointer of team queue
//head of winning team.
void FantasyGame::displayBattleWin(int inputDamageInflicted, Queue* inputQueue) {

    //Output tournament round number to user.
    std::cout << "TOURNAMENT ROUND " << tournamentRound << std::endl;

    //Output win information to user.
    std::cout << "WINNER" << std::endl;
    std::cout << "Winning Team:   " << inputQueue->getFront()->getTeam() << std::endl;


    //Output fighter information to user.
    inputQueue->getFront()->displayInfo();

    //Partially recover strength points of winning fighter.
    inputQueue->getFront()->recoverStr(inputDamageInflicted);

    //Display loss information to user.
    std::cout << "LOSER" << std::endl;
    std::cout << "Losing Team:    " << loserQueue.getFront()->getTeam() << std::endl;

    //Output fighter information to user.
    loserQueue.getFront()->displayInfo();

    std::cout << std::endl;
}

