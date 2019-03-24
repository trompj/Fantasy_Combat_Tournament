/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: Medusa Class - Derived from abstract Character class.
 * Variables: Static constant variables for Medusa character object setup. Allows for easy changes to
 * Medusa values.
 * Functions: Medusa Default Constructor - Sets charType to "Medusa" and feeds all constant int
 * values for Medusa class into Character class constructor to create Medusa object.
 * attack function - Overrides attack behaviour from pure virtual attack function in Character class.
 * Attack rolls die/dice for character to perform attack based on characters attack die type values.
 * Returns integer value for attack roll. For Medusa class, overridden attack function returns a die
 * roll value of 99 if a 12 out of 12 is rolled.
 * defense function - Calls default defense behaviour from Character class as no changes
 * are necessary in Medusa class for defense behaviour.
*/

#include "Medusa.hpp"

//Constructor with name input for Medusa- Sets medusa class values.
Medusa::Medusa(std::string inputName, std::string inputTeam) : Character(MEDUSA_ARMOR, MEDUSA_STRENGTH, MEDUSA_ATT_DIE_SIZE,
        MEDUSA_DEF_DIE_SIZE, MEDUSA_ATT_DICE, MEDUSA_DEF_DICE, inputName, inputTeam) {
    //Set character type to Medusa
    charType = "Medusa";
}

//Rolls die/dice for character to perform attack based on characters attack die type values.
//Returns integer value for attack roll. Function is overridden by Medusa class.
//In this class, if Medusa rolls a 12, she outputs a die roll value of 99 indicating that stare
//ability occurred, turning opponent to stone.
int Medusa::attack(int outputType) {
    int dieRollValue = 0;

    //Determine die roll
    for (int count = 0; count < numAttackDice; count++) {
        dieRollValue += randomInt(1, getAttDieSize());
    }

    //For output type #2, display complex output to screen
    if (outputType == 2) {
        if (dieRollValue == 12) {
            //Output attacker and roll value to user
            std::cout << charType << " rolled " << numAttackDice << " dice for an attack of " <<
                      dieRollValue << "." << std::endl;
            std::cout << charType << " attempted to use glare on opponent." << std::endl << std::endl;
        }

        //Regular attack roll occurs
        else {
            //Output attacker and roll value to user
            std::cout << charType << " rolled " << numAttackDice << " dice for an attack of " <<
                      dieRollValue << "." << std::endl << std::endl;
        }
    }
    //If roll is 12, medusa uses stare ability and returns a roll value of 99
    if (dieRollValue == 12) {
        dieRollValue = 99;
    }

    return dieRollValue;
}

//Calls Character class default defense function. For output type 2, display complex output.
void Medusa::defense(int inputAttackInt, int outputType) {
    Character::defense(inputAttackInt, outputType);
}