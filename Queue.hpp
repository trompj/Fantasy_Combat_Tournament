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
 * Queue Constructor - Sets head to nullptr at queue creation for empty queue.
 * Queue Destructor - Frees all allocated memory at program end.
 * queueRunMenu - Calls applicable menu functions and runs menu suite to control queue from centralized function. Calls
 * applicable functions based on user menu selection.
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "inputValidation.hpp"
#include "Menu.hpp"
#include "Character.hpp"

//Declare QueueNode struct
struct QueueNode {
    QueueNode* next;
    QueueNode* prev;
    Character* fighter;
};

class Queue {
private:
    QueueNode* head;

public:
    //Constructor sets head to nullptr for empty queue at queue creation.
    Queue();

    //Destructor to free all allocated memory
    ~Queue();

    //Add new node/new character to tail of list. Takes Character pointer and a QueueNode pointer to a pointer
    //for head of queue.
    void addCharBack(Character*);

    //Add a node to tail of list. Takes QueueNode pointer to a pointer as head of queue.
    void addFront(QueueNode* inputNode);

    //Add a node to tail of list. Takes QueueNode pointer to a pointer as head of queue.
    void addBack(QueueNode*);

    //Delete node from head of list
    void deleteFront();

    //Search team queue passed as parameter for number of character types passed as parameter as string value.
    //Return integer value for number of that character type present in team queue.
    int numCharTeam(std::string inputCharType);

    //Remove node from front of list and return removed node. Takes QueueNode pointer to pointer as parameter for
    //head pointer of queue to be manipulated.
    QueueNode* removeFront();

    //Traverse list and print values from head to tail
    void printQueue();

    //Return integer value of head node in queue (circular linked list)
    Character* getFront();

    //Checks to see if queue is empty
    bool isEmpty();
};

#endif //QUEUE_HPP
