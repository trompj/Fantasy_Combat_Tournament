/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: Barbarian Class - Derived from abstract Character class.
 * Variables: Static constant variables for barbarian character object setup. Allows for easy changes to
 * Barbarian values.
 * Functions: Barbarian Default Constructor - Sets charType to "Barbarian" and feeds all constant int
 * values for Barbarian class into Character class constructor to create Barbarian object.
 * attack function - Calls default attack behaviour from Character class as no changes
 * are necessary in Barbarian class for attack behaviour.
 * defense function - Calls default defense behaviour from Character class as no changes
 * are necessary in Barbarian class for defense behaviour.
*/

#include "Barbarian.hpp"

//Default Constructor - Sets barbarian class values to character class.
Barbarian::Barbarian(std::string inputName, std::string inputTeam) : Character(BARB_ARMOR, BARB_STRENGTH, BARB_ATT_DIE_SIZE,
        BARB_DEF_DIE_SIZE, BARB_ATT_DICE, BARB_DEF_DICE, inputName, inputTeam) {
    //Set character type to Barbarian
    charType = "Barbarian";
}

//Calls default attack behaviour from Character class
int Barbarian::attack(int outputType) {
    return Character::attack(outputType);
}

//Calls default defense behaviour from Character class
void Barbarian::defense(int inputInt, int outputType) {
    Character::defense(inputInt, outputType);
}