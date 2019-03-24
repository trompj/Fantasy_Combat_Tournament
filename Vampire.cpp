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

#include "Vampire.hpp"

//Default Constructor - Sets vampire class values to character class.
Vampire::Vampire(std::string inputName, std::string inputTeam) : Character(VAMP_ARMOR, VAMP_STRENGTH, VAMP_ATT_DIE_SIZE,
        VAMP_DEF_DIE_SIZE, VAMP_ATT_DICE, VAMP_DEF_DICE, inputName, inputTeam) {
    //Set character type to Vampire
    charType = "Vampire";
}

//Overridden defense function from Character class. Performs same function as Character class, except
//it accounts for a 50% chance that no attack occurs due to charm ability. Takes int as parameter
//for damage done during attack.
void Vampire::defense(int inputDamage, int outputType) {
    int dieRollValue = 0;

    bool charmOccurred = false;
    //Generate 0 or 1 randomly to determine whether or not Vampire charmed attacker
    charmOccurred = randomInt(0, 1);
    if (charmOccurred) {
        //Display screen output if outputType 2 is requested.
        if (outputType == 2) {
            std::cout << "Vampire charmed attacker into not performing an attack." << std::endl;
        }
    }

    //Vampire did not charm attacker, perform defense normally
    else {
        //Character is turned to stone
        if (inputDamage == 99) {
            //Display output if outputType 2 is requested.
            if (outputType == 2) {
                std::cout << charType << " is turned to stone before it can mount a defense." << std::endl;
            }

            //Add damage to defending character
            takeDamage(99, outputType);
        }
        //Character is not turned to stone, calculate defense normally.
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
            }

            //If no damage occurs, output message to user.
            if (damageInflicted <= 0) {
                //Output results to screen if complex outputType 2 is requested.
                if (outputType == 2) {
                    std::cout << charType << " defended itself from all attacks this round!" << std::endl;
                }
            }

            //Damage occurs to defender
            else {
                //Adjust strength value of character object
                takeDamage(damageInflicted, outputType);
            }
        }
    }

    //Output results to screen if complex outputType 2 is requested.
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

//Calls default attack behaviour from Character class
int Vampire::attack(int outputType) {
    return Character::attack(outputType);
}