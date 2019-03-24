/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: Vampire Class - Derived from abstract Character class.
 * Variables: Static constant variables for Vampire character object setup. Allows for easy changes to
 * Vampire values.
 * Functions: Vampire Default Constructor - Sets charType to "Vampire" and feeds all constant int
 * values for Vampire class into Character class constructor to create Vampire object.
 * attack function - Calls default attack function behaviour from Character class as no changes
 * are necessary in Vampire class for attack behaviour.
 * defense function - Overridden defense function from Character class. Performs same function as Character class,
 * except it accounts for a 50% chance that no attack occurs due to charm ability. Takes int as parameter
 * for damage done during attack.
*/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character {
private:
    static const int VAMP_ATT_DICE = 1;
    static const int VAMP_ATT_DIE_SIZE = 12;
    static const int VAMP_DEF_DICE = 1;
    static const int VAMP_DEF_DIE_SIZE = 6;
    static const int VAMP_STRENGTH = 18;
    static const int VAMP_ARMOR = 1;

public:

    //Constructor with name added - Sets vampire class values to character class.
    Vampire(std::string, std::string);

    //Overridden defense function from Character class. Performs same function as Character class, except
    //it accounts for a 50% chance that no attack occurs due to charm ability. Takes int as parameter
    //for damage done during attack.
    //Takes first int parameter for attack roll value, second int parameter for output type.
    //1 is simple/no output, 2 is complex defense output.
    void defense(int, int);

    //Calls default attack behaviour from Character class. Takes int value for outputType,
    //1 for simple/no screen output, 2 for complex screen output.
    int attack(int);
};


#endif //VAMPIRE_HPP
