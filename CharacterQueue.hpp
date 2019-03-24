/* Author: Justin Tromp
 * Email: trompj@oregonstate.edu
 * Date Created: 02/16/2019
 * Description: Queue class contains declaration for QueueNode struct. Each QueueNode consists of a QueueNode pointer
 * variable next and QueueNode pointer variable prev as well as an integer variable val to hold integer data for each
 * node in queue.
 * Class Variable: head - QueueNode pointer that points to the first node in the circular linked list.
 * Class Functions: addBack - Takes an integer value as parameter and adds a new QueueNode at the back of the
 * queue/list.
 * removeFront - Removes and frees memory of first node in queue.
 * printQueue - Prints values of queue to screen for user viewing from first node in queue through last node in queue.
 * If queue is empty, function informs user of such.
 * getFront - Prints value of first node in queue for user if queue is not empty. If queue is empty, informs user of
 * such.
 * isEmpty - Checks if queue is empty and returns a boolean value accordingly. True for empty and false for not empty.
 * userMenu - Prints out menu options to user and accepts input/calls integer validation function to validate user
 * selection. Returns integer value to calling function for selection.
 * intInputRequest - Ask user what integer value they would like a new node to contain and return integer. User int
 * input is validated through validation function.
 * validateInputRangeInt - Validate integer input from min through max int parameters passed to function. Re-prompts
 * user if not a valid int value entry.
 * validateIntInput - Validate integer input (negative or positive integer values). Returns validated int value and
 * re-prompts user if not a valid integer entry.
 * Queue Constructor - Sets head to nullptr at queue creation for empty queue.
 * Queue Destructor - Frees all allocated memory at program end.
 * queueRunMenu - Calls applicable menu functions and runs menu suite to control queue from centralized function. Calls
 * applicable functions based on user menu selection.
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "Character.hpp"

//Declare QueueNode struct
struct QueueNode {
    QueueNode* next;
    QueueNode* prev;
    Character* combatCharacter;
};

class CharacterQueue {
private:
    QueueNode* head;

public:
    //Constructor sets head to nullptr for empty queue at queue creation.
    CharacterQueue();

    //Destructor to free all allocated memory
    ~CharacterQueue();

    //Run queue menu and queue manipulation functions.
    void queueRunMenu();

    //Add new node to tail of list. Takes int value as parameter to set node value to.
    void addBack(Character*, QueueNode **);

    //Delete node from head of list
    void removeFront();

    //Traverse list and print values from head to tail
    void printQueue();

    //Return character value of head node in queue (circular linked list)
    Character* getFront();

    //Checks to see if queue is empty
    bool isEmpty(QueueNode*);

    //Menu to manipulate circular linked list (queue) based on user input. Returns integer
    //value for user selection.
    int userMenu();

    //Ask user what integer value they would like a new node to contain and return integer
    int intInputRequest();

    //Validate integer input from min through max parameters passed to function
    int validateInputRangeInt(int min, int max);

    //Validate integer input (negative or positive integer values)
    int validateIntInput();
};


#endif //QUEUE_HPP
