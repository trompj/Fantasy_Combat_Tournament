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

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {
private:
    static const int BARB_ATT_DICE = 2;
    static const int BARB_ATT_DIE_SIZE = 6;
    static const int BARB_DEF_DICE = 2;
    static const int BARB_DEF_DIE_SIZE = 6;
    static const int BARB_STRENGTH = 12;
    static const int BARB_ARMOR = 0;

public:
    //Constructor passes name of fighter and sets barbarian class values to character class.
    Barbarian(std::string, std::string);

    //Calls default attack behaviour from Character class
    int attack(int);

    //Calls default defense behaviour from Character class
    void defense(int, int);

};


#endif //BARBARIAN_HPP
