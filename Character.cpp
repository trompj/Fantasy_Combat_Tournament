/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: Character class - Base abstract class for all fantasy character types (Barbarian,
 * Blue Men, Harry Potter, Vampire, Medusa)
 * Variables: charType (string value for type of character), armor (int value for armor rating),
 * attackDieSize (int value for number of sides per attack die), defenseDieSize (int value for
 * number of sides per defense die), numAttackDice/numDefenseDice (int value for number of
 * attack and defense dice used by character type).
 * Functions: setArmor - Takes int value and sets value to armor rating of character.
 * setStrength - Takes int value and sets value to strength rating of character.
 * setDice - Takes all aspects of dice (size and number) for attack/defense and sets up character
 * values.
 * setCharType - Takes string as parameter and sets to character type.
 * takeDamage - Virtual function that takes int value as parameter for damage inflicted and applies
 * damage to characters strength.
 * randomInt - Takes min and max int values to be output as parameters and returns random
 * value in range.
 * Character Default Constructor - Set all values for Character class object to 0.
 * Character Constructor - Take 6 integers as parameters to create Character class object according
 * to values passed.
 * Default Virtual Character Destructor
 * getArmor - Returns integer value for armor rating of object.
 * getStrength - Returns integer value for strength of object.
 * getAttDieSize - Returns int value for sides of attack dice for character object.
 * getDefDieSize - Returns int value for sides of defense dice for character object.
 * getCharType - Returns string value for charType (Such as "Barbarian"). Used in outputs to user.
 * Pure Virtual attack - Contains a default attack function that can be called by classes that do
 * not need a separate function type. Returns calculated int value for attack rolls.
 * Pure Virtual defense - Contains a default defense function that can be called by classes that do
 * not need a separate function type. Outputs defense information for character object calling
 * function. Takes attack roll integer value as parameter.
 * displayDefenderInfo - Outputs defender information to screen for user, such as charType,
 * strength value, and armor rating.
*/

#include "Character.hpp"

//Constructor takes four integer parameters for armor, strength, and attack/defense die sizes.
//Constructor also takes two integer values for number of attack and number of defense dice.
//Two string parameters at end of constructor initiate name of fighter and name of team.
Character::Character(int inputArmor, int inputStrength, int inputAttDieSize, int inputDefDieSize,
        int inputNumAttDice, int inputNumDefDice, std::string inputName, std::string inputTeam) {

    charType = "";
    charName = inputName;
    armor = inputArmor;
    strength = inputStrength;
    team = inputTeam;

    setDice(inputAttDieSize, inputDefDieSize, inputNumAttDice, inputNumDefDice);
}

//Default constructor
Character::Character() {
    armor = 0;
    strength = 0;
    setDice(0, 0, 0, 0);
}

//Destructor
Character::~Character() {}

/*
//Set string passed as parameter to character type
void Character::setCharType(std::string inputType) {
    charType = inputType;
}*/

//Set integer passed as parameter to armor
void Character::setArmor(int inputArmor) {
    armor = inputArmor;
}

//Set integer passed as parameter to strength
void Character::setStrength(int inputStrength) {
    strength = inputStrength;
}

//Set integers passed as parameters to dice values. Sets size of attack and defense dice and sets
//number of dice for attack and defense of character
void Character::setDice(int inputAttDieSize, int inputDefDieSize, int inputNumAttDice,
        int inputNumDefDice) {
    attackDieSize = inputAttDieSize;
    defenseDieSize = inputDefDieSize;
    numAttackDice = inputNumAttDice;
    numDefenseDice = inputNumDefDice;
}

//Return string value for character type
std::string Character::getCharType() {
    return charType;
}

//Return integer value for number of die sides for character attack
int Character::getAttDieSize() {
    return attackDieSize;
}

//Return integer value for number of die sides for character defense
int Character::getDefDieSize() {
    return defenseDieSize;
}

//Return integer value for armor
int Character::getArmor() {
    return armor;
}

//Return integer value for strength
int Character::getStrength() {
    return strength;
}

//Rolls die/dice for character to perform attack based on characters attack die type values.
//Returns integer value for attack roll. Function is overridden by Medusa class and default
//attack function is called by other character object class types.
//Takes integer as parameter, 1 for simplified attack with no output, 2 for full attack output.
int Character::attack(int outputType) {
    int dieRollValue = 0;

    for (int count = 0; count < numAttackDice; count++) {
        dieRollValue += randomInt(1, getAttDieSize());
    }

    if (outputType == 2) {
        std::cout << charType << " rolled " << numAttackDice << " dice for an attack of " <<
                  dieRollValue << "." << std::endl << std::endl;
    }

    return dieRollValue;
}

//Rolls die/dice for character to perform defense based on characters defense die type values.
//Returns character integer defense die/dice roll value for defense. Function is overridden by
//vampire class and default defense function is called by other character object class types.
//Takes two int parameters, first for attack roll value and second for type of output. 1 for
//simplified attack with no output, 2 for full attack with output.
void Character::defense(int inputDamage, int outputType) {
    int dieRollValue = 0;

    //Character is turned to stone
    if (inputDamage == 99) {
        //Output results to screen if complex outputType 2 is requested.
        if (outputType == 2) {
            std::cout << charType << " is turned to stone before it can mount a defense." << std::endl;
        }

        //Add damage to defending character
        takeDamage(99, outputType);
    }

    //Normal character defense occurs
    else {
        //Roll dice for defense
        for (int count = 0; count < numDefenseDice; count++) {
            dieRollValue += randomInt(1, getDefDieSize());
        }

        int damageInflicted = 0;
        //Calculate damage inflicted to character object.
        damageInflicted = inputDamage - dieRollValue - getArmor();

        //If more defense is rolled than damage inflicted, set damage inflicted to 0.
        if (damageInflicted < 0) {
            damageInflicted = 0;
        }

        //Output results to screen if complex outputType 2 is requested.
        if (outputType == 2) {
            //Output to user that character is attempting to defend.
            std::cout << charType << " is attempting to defend from attack!" << std::endl;
            std::cout << charType << " rolled " << numDefenseDice << " dice to generate " << dieRollValue
                      << " defense points." << std::endl << std::endl;

            //Output defense calculation to user
            std::cout << "DAMAGE CALCULATION: Damage Inflicted = Attack Damage - Defense Roll - Armor" << std::endl;
            std::cout << "Attack Damage:    " << inputDamage << std::endl;
            std::cout << "Defense Die Roll: " << dieRollValue << std::endl;
            std::cout << "Defense Armor:    " << getArmor() << std::endl;
            std::cout << "Damage Inflicted: " << damageInflicted << " (Set to 0 if less than 0 damage inflicted)"
                      << std::endl << std::endl;

            //If no damage occurs, output message to user.
            if (damageInflicted <= 0) {
                std::cout << charType << " defended itself from all attacks this round!" << std::endl;
            }
        }

        //Damage occurs to defender
        if (damageInflicted > 0) {
            //Adjust strength value of character object
            takeDamage(damageInflicted, outputType);
        }
    }

    if (outputType == 2) {
        //Output strength value to user
        std::cout << charType << " strength value is now " << strength << " after defense." << std::endl;

        //If strength goes to 0 or less than 0, character dies. Output message to user.
        if (strength <= 0) {
            std::cout << charType << " did not survive the attack and has died!" << std::endl;
        }
            //Character survived attack
        else {
            std::cout << charType << " has survived the attack!" << std::endl;
        }

        std::cout << std::endl;
    }
}

//Integer value for damage inflicted is passed to function. Function takes that value and adjusts
//damage done to current character. Function is overridden in BlueMen and HarryPotter classes.
//Takes two integer parameters, first for damage inflicted, second for outputType 1 for simple/no
//output, 2 for complete output. Output type is only used in Harry Potter and Blue Men classes.
void Character::takeDamage(int inputDamageInflicted, int outputType) {
    strength -= inputDamageInflicted;

    //If strength is reduced below 0, set to 0
    if (strength < 0) {
        strength = 0;
    }
}

//Randomly generate integer within parameters given. Two integer parameters determine the min
//through the max values that may be generated.
int Character::randomInt(int minVal, int maxVal) {
    //Obtain seed for random number engine
    std::random_device randomNumDevice;

    //Mersenne_twister_engine seeded with rd
    std::mt19937 generateNum(randomNumDevice());
    std::uniform_int_distribution<> dis(minVal, maxVal);

    return dis(generateNum);
}

//Print out character information to screen (type, armor rating, and current strength value)
void Character::displayDefenderInfo() {
    //Display defender information to user
    std::cout << "Defender: " << charType << std::endl;
    std::cout << "Armor:    " << armor << std::endl;
    std::cout << "Strength  " << strength << std::endl << std::endl;
}

//Print out fighter information to screen (type and name of fighter)
void Character::displayInfo() {
    //Display defender information to user
    std::cout << "Character Type: " << charType << std::endl;
    std::cout << "Fighter Name:   " << charName << std::endl;
}

//Recover percentage of strength points lost if winner of match. Takes in integer value
//of number of strength points lost in battle. Return int value for amount of damage
//recovered to calling function.
void Character::recoverStr(int inputTotalDamage) {
    int damageRecovered = 0;
    double percentDamageRec = 0;

    //If there was damage done to character, initiate partial recovery.
    //If no damage was inflicted, no recovery occurs.
    if (inputTotalDamage > 0) {
        percentDamageRec = randomInt(1, 9) * .1;

        damageRecovered = (int) trunc(percentDamageRec * inputTotalDamage);

        this->strength += damageRecovered;

        std::cout << "Winning fighter " << this->charName << " has recovered " << damageRecovered << " strength points." << std::endl;
    }

    else {
        std::cout << "Winning fighter did not take any damage this battle. No damage was recovered." << std::endl;
    }

    std::cout << std::endl;
}

//Return string value for team name to calling function.
std::string Character::getTeam() {
    return team;
}

