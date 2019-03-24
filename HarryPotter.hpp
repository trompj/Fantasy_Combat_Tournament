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

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {
private:
    static const int HARRY_POTTER_ATT_DICE = 2;
    static const int HARRY_POTTER_ATT_DIE_SIZE = 6;
    static const int HARRY_POTTER_DEF_DICE = 2;
    static const int HARRY_POTTER_DEF_DIE_SIZE = 6;
    static const int HARRY_POTTER_STRENGTH = 10;
    static const int HARRY_POTTER_ARMOR = 0;
    static const int HARRY_POTTER_HOGWARTS_STR = 20;

    int harryPotterLives = 0;

    //Activates Harry Potter ability upon death, bringing character object
    //back to life and sets strength to 20.
    //Takes int value as parameter for outputType. 1 for no/simple output to screen and 2 for
    //complete output to screen.
    void hogwartsAbility(int);

    //Integer value for damage inflicted is passed to function. Function takes that value and adjusts
    //damage done to current character. Function is overridden in HarryPotter class. In this class
    //the strength level of Harry Potter is checked after damage is inflicted. If hits 0 or less for
    //first life, Harry Potter activates hogwartsAbility.
    //Takes two int parameters, first is damage inflicted and second is for type of output. 1 for
    //simple/no output to screen and 2 for complete visualization.
    void takeDamage(int, int);

public:
    //Constructor passes fighter string name value and sets harry potter class values through Character class .
    HarryPotter(std::string, std::string);

    //Calls default attack behaviour from Character class
    int attack(int);

    //Calls default defense behaviour from Character class
    void defense(int, int);
};

#endif //HARRYPOTTER_HPP
