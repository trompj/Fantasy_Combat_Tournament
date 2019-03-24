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

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {
private:
    static const int MEDUSA_ATT_DICE = 2;
    static const int MEDUSA_ATT_DIE_SIZE = 6;
    static const int MEDUSA_DEF_DICE = 1;
    static const int MEDUSA_DEF_DIE_SIZE = 6;
    static const int MEDUSA_STRENGTH = 8;
    static const int MEDUSA_ARMOR = 3;

public:

    //Constructor with string name input - Sets medusa class values through Character class.
    Medusa(std::string, std::string);

    //Rolls die/dice for character to perform attack based on characters attack die type values.
    //Returns integer value for attack roll. Function is overridden by Medusa class.
    //In this class, if Medusa rolls a 12, she outputs a die roll value of 99 indicating that stare
    //ability occurred, turning opponent to stone.
    //Takes integer value as parameter to determine screen output type, 1 for simple, 2 for complex.
    int attack(int);

    //Calls Character class default defense function. For output type 2, display complex output.
    void defense(int, int);
};


#endif //MEDUSA_HPP
