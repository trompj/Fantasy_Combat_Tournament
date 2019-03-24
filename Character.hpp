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

#ifndef character_hpp
#define character_hpp

#include <iostream>
#include <random>

class Character {
protected:
    std::string charType = "";
    std::string charName = "";
    int armor = 0;
    int strength = 0;
    int attackDieSize = 0;
    int defenseDieSize = 0;
    int numAttackDice = 0;
    int numDefenseDice = 0;
    std::string team = "";

    //Set integer passed as parameter to armor
    void setArmor(int);

    //Set integer passed as parameter to strength
    void setStrength(int);

    //Set integers passed as parameters to dice values. Sets size of attack and defense dice and sets
    //number of dice for attack and defense of character
    void setDice(int, int, int, int);

    //Integer value for damage inflicted is passed to function. Function takes that value and adjusts
    //damage done to current character. Function is overridden in BlueMen and HarryPotter classes.
    //Takes two integer parameters, first for damage inflicted, second for outputType 1 for simple/no
    //output, 2 for complete output.
    virtual void takeDamage(int, int);

    //Randomly generate integer within parameters given. Two integer parameters determine the min
    //through the max values that may be generated.
    int randomInt(int, int);

public:
    //Constructor takes four integer parameters for armor, strength, and attack/defense die sizes.
    //Constructor also takes two integer values for number of attack and number of defense dice.
    //Two string parameters at end of constructor initiate name of fighter and name of team.
    Character(int, int, int, int, int, int, std::string, std::string);

    //Default constructor
    Character();

    //Destructor
    virtual ~Character();

    //Return integer value for armor
    int getArmor();

    //Return integer value for strength
    int getStrength();

    //Return integer value for number of die sides for character
    int getAttDieSize();

    //Return integer value for number of die sides for character defense
    int getDefDieSize();

    //Return string value for team name to calling function.
    std::string getTeam();

    //Return string value for character type
    std::string getCharType();

    //Rolls die/dice for character to perform attack based on characters attack die type values.
    //Returns integer value for attack roll. Function is overridden by Medusa class.
    //Takes integer as parameter, 1 for simplified attack with no output, 2 for full attack output.
    virtual int attack(int) = 0;

    //Rolls die/dice for character to perform defense based on characters defense die type values.
    //Function is overridden by Vampire class.
    //Takes two int parameters, first for attack roll value and second for type of output. 1 for
    //simplified attack with no output, 2 for full attack with output.
    virtual void defense(int, int) = 0;

    //Print out character information to screen (type, armor rating, and current strength value)
    void displayDefenderInfo();

    //Print out fighter information to screen (type and name of fighter)
    void displayInfo();

    //Recover percentage of strength points lost if winner of match. Takes in integer value
    //of number of strength points lost in battle. Return int value for amount of damage
    //recovered to calling function.
    void recoverStr(int);
};

#endif //CHARACTER_HPP
