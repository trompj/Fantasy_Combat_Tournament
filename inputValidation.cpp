/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/08/2019
 * Description: Validation functions used in fantasy combat simulation.
 * validateInputRangeInt - Validate integer input from min through max parameters passed to function.
 * stringUpperCase - Takes string as parameter and returns string in all upper case.
*/

#include "inputValidation.hpp"

//Validate integer input from min through max parameters passed to function
int validateInputRangeInt (int min, int max) {
    int userInput = 0;
    std::string userStringInput = " ";

    //Accept input from user
    getline(std::cin, userStringInput);

    //If input is an integer, store value in userInput
    if (std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit) && !userStringInput.empty()) {
        userInput = std::stoi(userStringInput);
    }

    bool inputNotValidated = false;
    //As long as user inputs non-digits, loop to request correct input
    while ((!std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) || inputNotValidated ||
           (userStringInput.empty()) || userInput < min || userInput > max) {

        //Change to true as user input must be validated before placing in userInput as integer
        inputNotValidated = true;

        //Re-prompt user for input
        std::cout << "Please enter a valid integer (i.e., without decimals) and within "
                     "the previously specified range." << std::endl;

        //Accept input from user
        getline(std::cin, userStringInput);

        //If conditions are met, move user input from string to integer variable and update input validation
        //boolean value to allow loop exit.
        if ((std::all_of(userStringInput.begin(), userStringInput.end(), ::isdigit)) && !userStringInput.empty()) {
            userInput = std::stoi(userStringInput);
            inputNotValidated = false;
        }
    }

    return userInput;
}

//Takes string value as parameter and capitalizes all letters, returning capitalized string value to
//calling function.
std::string stringUpperCase(std::string inputString) {
    //Capitalize all letters in user entered name to allow for easier entry
    for (unsigned count = 0; count < inputString.length(); count++) {
        inputString[count] = std::toupper(inputString[count]);
    }

    return inputString;
}