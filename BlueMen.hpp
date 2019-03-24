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

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character {
private:
    static const int BLUE_MEN_ATT_DICE = 2;
    static const int BLUE_MEN_ATT_DIE_SIZE = 10;
    static const int BLUE_MEN_DEF_DICE = 3;
    static const int BLUE_MEN_DEF_DIE_SIZE = 6;
    static const int BLUE_MEN_STRENGTH = 12;
    static const int BLUE_MEN_ARMOR = 3;

    //Checks strength level of BlueMen object and adjusts number of defense dice
    //accordingly.
    //Takes int parameter for output type, 1 for no screen output, 2 for all output.
    void mobAbility(int);

    //Integer value for damage inflicted is passed to function. Function takes that value and adjusts
    //damage done to class object. Function is overridden in BlueMen class. In this class
    //the number of defense dice in play is adjusted according to how much strength the character
    //has.
    //Takes two int parameters, first is for damage inflicted, second is for outputType.
    //1 for simplified/no output to screen, 2 for complex.
    void takeDamage(int, int);

public:

    //Constructor with character name input - Sets vampire class values.
    BlueMen(std::string, std::string);

    //Calls Character class default attack function.
    int attack(int);

    //Calls Character class default defense function.
    void defense(int, int);
};

#endif //BLUEMEN_HPP
