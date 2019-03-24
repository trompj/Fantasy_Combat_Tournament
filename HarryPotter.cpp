/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: HarryPotter Class - Derived from abstract Character class.
 * Variables: Static constant variables for HarryPotter character object setup. Allows for easy changes to
 * HarryPotter values. One additional value for HarryPotter class is an int value for harryPotterLives.
 * Functions: HarryPotter Default Constructor - Sets charType to "Harry Potter" and feeds all constant int
 * values for HarryPotter class into Character class constructor to create BlueMen object. Additionally,
 * HarryPotter class objects set lives to 2 for hogwarts special ability.
 * hogwartsAbility - Checks strength level of HarryPotter object. If strength drops below 0 and HarryPotter
 * has 2 lives left, set strength to 20 for hogwarts strength value and reduce lives by 1. Output message
 * to user informing that special ability was used.
 * takeDamage - Takes int value as parameter for damage inflicted. Function takes damage value and
 * adjusts strength level of class object. In HarryPotter class, takeDamage is overridden and calls
 * hogwartsAbility.
 * attack function - Calls default attack behaviour from Character class as no changes
 * are necessary in HarryPotter class for attack behaviour.
 * defense function - Calls default defense behaviour from Character class as no changes
 * are necessary in HarryPotter class for defense behaviour.
*/

#include "HarryPotter.hpp"

//Default Constructor - Sets harry potter class values.
HarryPotter::HarryPotter(std::string inputName, std::string inputTeam) : Character(HARRY_POTTER_ARMOR, HARRY_POTTER_STRENGTH, HARRY_POTTER_ATT_DIE_SIZE,
        HARRY_POTTER_DEF_DIE_SIZE, HARRY_POTTER_ATT_DICE, HARRY_POTTER_DEF_DICE, inputName, inputTeam) {
    //Set character type to Harry Potter
    charType = "Harry Potter";

    //Set lives of Harry Potter
    harryPotterLives = 2;
}

//Activates Harry Potter ability upon death, bringing character object
//back to life and sets strength to 20.
void HarryPotter::hogwartsAbility(int outputType) {
    //If strength is less than or equal to 0, set strength to 20
    if (strength <= 0 && harryPotterLives == 2) {
        //Output message to user indicating event occurred (if complete output is requested)
        if (outputType == 2) {
            std::cout << "Harry Potter took a deadly blow but he is back to life at double strength!" << std::endl;
        }

        //Set strength to hogwarts strength value
        strength = HARRY_POTTER_HOGWARTS_STR;

        //Set Harry Potter lives to 1
        harryPotterLives = 1;
    }
}

//Integer value for damage inflicted is passed to function. Function takes that value and adjusts
//damage done to current character. Function is overridden in HarryPotter class. In this class
//the strength level of Harry Potter is checked after damage is inflicted. If hits 0 or less for
//first life, Harry Potter activates hogwartsAbility.
//Takes two int parameters, first is damage inflicted and second is for type of output. 1 for
//simple/no output to screen and 2 for complete visualization.
void HarryPotter::takeDamage(int inputDamageInflicted, int outputType) {
    //Update strength of this object from damage inflicted
    strength -= inputDamageInflicted;

    //Check if hogwarts ability should be used
    hogwartsAbility(outputType);

    //If strength is reduced below 0, set to 0
    if (strength < 0) {
        strength = 0;
    }
}

//Calls default attack behaviour from Character class
int HarryPotter::attack(int outputType) {
    return Character::attack(outputType);
}

//Calls default defense behaviour from Character class
void HarryPotter::defense(int inputAttackInt, int outputType) {
    Character::defense(inputAttackInt, outputType);
}