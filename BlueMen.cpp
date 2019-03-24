/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: BlueMen Class - Derived from abstract Character class.
 * Variables: Static constant variables for BlueMen character object setup. Allows for easy changes to
 * BlueMen values.
 * Functions: BlueMen Default Constructor - Sets charType to "Blue Men" and feeds all constant int
 * values for Blue Men class into Character class constructor to create BlueMen object.
 * mobAbility - Checks strength level of BlueMen object and adjusts number of defense dice
 * accordingly.
 * takeDamage - Takes int value as parameter for damage inflicted. Function takes damage value and
 * adjusts strength level of class object. In BlueMen class, takeDamage calls mobAbility to adjust
 * defense dice.
 * attack function - Calls default attack behaviour from Character class as no changes
 * are necessary in BlueMen class for attack behaviour.
 * defense function - Calls default defense behaviour from Character class as no changes
 * are necessary in BlueMen class for defense behaviour.
*/

#include "BlueMen.hpp"

//Default Constructor - Sets blue men class values.
BlueMen::BlueMen(std::string inputName, std::string inputTeam) : Character(BLUE_MEN_ARMOR, BLUE_MEN_STRENGTH, BLUE_MEN_ATT_DIE_SIZE,
        BLUE_MEN_DEF_DIE_SIZE, BLUE_MEN_ATT_DICE, BLUE_MEN_DEF_DICE, inputName, inputTeam) {
    //Set character type to Blue Men
    charType = "Blue Men";
}

//Checks strength level of BlueMen object and adjusts number of defense dice
//accordingly.
//Takes int parameter for output type, 1 for no screen output, 2 for all output.
void BlueMen::mobAbility(int outputType) {
    //Check to see if a condition for the first blue man to die exists and has not happened already.
    //Output message to user informing of event and change number of dice in play.
    if (strength <= 8 && strength > 4 && numDefenseDice == 3) {
        if (outputType == 2) {
            std::cout << "One of the blue men have died! There are now only 2 defense dice in play." << std::endl;
        }
        numDefenseDice = 2;
    }

    //Check to see if a condition for 2 blue men dead exists and has not happened already.
    //Output message to user informing them of event and change number of dice in play.
    else if (strength > 0 && strength <= 4 && (numDefenseDice == 3 || numDefenseDice == 2)) {
        //If number of defense dice in use is 3, two blue men have died and inform user of such
        if (numDefenseDice == 2) {
            if (outputType == 2) {
                std::cout << "One more of the blue men have died! There is now only 1 defense die in play."
                    << std::endl;
            }
        }

        //If number of defense dice in use is 2, one of the blue men have died and inform user of such
        else if (numDefenseDice == 3) {
            if (outputType == 2) {
                std::cout << "Two of the blue men have died! There is now only 1 defense die in play." << std::endl;
            }
        }
        numDefenseDice = 1;
    }
}

//Integer value for damage inflicted is passed to function. Function takes that value and adjusts
//damage done to current character. Function is overridden in BlueMen class. In this class
//the number of defense dice in play is adjusted according to how much strength the character
//has.
//Takes two int parameters, first is for damage inflicted, second is for outputType.
//1 for simplified/no output to screen, 2 for complex.
void BlueMen::takeDamage(int inputDamageInflicted, int outputType) {
    //Update strength of this object
    strength -= inputDamageInflicted;

    //Check strength level and reduce number of defense dice accordingly
    mobAbility(outputType);

    //If strength is reduced below 0, set to 0
    if (strength < 0) {
        strength = 0;
    }
}

//Calls Character class default attack function.
int BlueMen::attack(int outputType) {
    return Character::attack(outputType);
}

//Calls Character class default defense function.
void BlueMen::defense(int inputAttackInt, int outputType) {
    Character::defense(inputAttackInt, outputType);
}