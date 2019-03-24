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

#include "Queue.hpp"

//Default constructor sets head to nullptr for empty queue.
Queue::Queue() {
    head = nullptr;
}

//Destructor to free all allocated memory
Queue::~Queue() {
    //Loop through list and free allocated memory for nodes.
    while (head != nullptr) {
        deleteFront();
    }
}

//Checks to see if queue is empty
bool Queue::isEmpty() {
    //Set to true as default
    bool queueEmpty = true;

    //If queue is not empty, set bool value to false.
    if (head != nullptr) {
        queueEmpty = false;
    }

    return queueEmpty;
}

//Add new node to end of list. Takes int value as parameter to set node value to.
void Queue::addCharBack(Character* inputChar) {
    //Create new node that does not point to anything and holds integer value.
    QueueNode* newNode = new QueueNode;

    //Set value according to integer passed as parameter.
    newNode->fighter = inputChar;

    //If queue is empty, add QueueNode as if list is empty.
    if (isEmpty()) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    //If queue is not empty, add QueueNode to end of circular list.
    else {
        //Declare/set tempPtrLast to last node in list.
        QueueNode* tempPtrLast = head->prev;

        //Set last node in queue to point to newNode.
        tempPtrLast->next = newNode;

        //Set newNode to point to previous last node and to the first node in queue.
        newNode->prev = tempPtrLast;
        newNode->next = head;

        //Set first node previous to point to newNode being placed at end.
        head->prev = newNode;
    }
}

//Add a node to tail of list. Takes QueueNode pointer to a pointer as head of queue.
void Queue::addBack(QueueNode* inputNode) {
    //If queue is empty, add QueueNode as if list is empty.
    if (isEmpty()) {
        inputNode->next = inputNode;
        inputNode->prev = inputNode;
        head = inputNode;
    }
    //If queue is not empty, add QueueNode to end of circular list.
    else {
        //Declare/set tempPtrLast to last node in list.
        QueueNode* tempPtrLast = head->prev;

        //Set last node in queue to point to newNode.
        tempPtrLast->next = inputNode;

        //Set newNode to point to previous last node and to the first node in queue.
        inputNode->prev = tempPtrLast;
        inputNode->next = head;

        //Set first node previous to point to newNode being placed at end.
        head->prev = inputNode;
    }
}

//Delete node from front of list
void Queue::deleteFront() {
    //If queue is empty, inform user of such and do not remove front node.
    if (isEmpty()) {
        std::cout << "Queue is empty! Node cannot be removed from front of queue." << std::endl << std::endl;
    }
    //If queue is not empty, remove node from front of the queue.
    else {
        //Declare/set tempPtrFront to first node in list.
        QueueNode* tempPtrFront = head;

        //If there is only one node in queue, set head to nullptr.
        if (tempPtrFront->next == tempPtrFront) {
            head = nullptr;
        }

        //Set head to new head node (2nd node in queue) if more than one node is present in queue.
        else {
            //Head set to 2nd node in queue.
            head = tempPtrFront->next;

            //Reassign prev pointer of new head node.
            head->prev = tempPtrFront->prev;

            //Reassign next pointer of last node in queue
            tempPtrFront->prev->next = head;
        }

        delete tempPtrFront->fighter;

        delete tempPtrFront;
    }
}

//Remove node from front of list and return removed node. Takes QueueNode pointer to pointer as parameter for
//head pointer of queue to be manipulated.
QueueNode* Queue::removeFront() {
    //If queue is empty, inform user of such and do not remove front node.
    if (isEmpty()) {
        std::cout << "Queue is empty! Node cannot be removed from front of queue." << std::endl << std::endl;

        return nullptr;
    }
        //If queue is not empty, remove node from front of the queue.
    else {
        //Declare/set tempPtrFront to first node in list.
        QueueNode* tempPtrFront = head;

        //If there is only one node in queue, set head to nullptr.
        if (tempPtrFront->next == tempPtrFront) {
            head = nullptr;
        }

        //Set head to new head node (2nd node in queue) if more than one node is present in queue.
        else {
            //Head set to 2nd node in queue.
            head = tempPtrFront->next;

            //Reassign prev pointer of new head node.
            head->prev = tempPtrFront->prev;

            //Reassign next pointer of last node in queue
            tempPtrFront->prev->next = head;
        }

        return tempPtrFront;
    }
}

//Traverse list and print out integer values to screen stored in each node for user
void Queue::printQueue() {
    //Check list to see if it is empty, if it is, inform user that it is empty
    if (!isEmpty()) {
        QueueNode* temp = head;

        //Loop through and print fighters held in each node in pile.
        do {
            //Print value of temp pointer (current fighter)
            temp->fighter->displayInfo();

            //Print team of temp pointer (current fighter)
            std::cout << temp->fighter->getTeam() << std::endl;

            //Set temp pointer to next node in list
            temp = temp->next;

        } while (temp != head);
    }

    //List is empty, so inform user that it is empty
    else {
        std::cout << "The queue is empty. No contents to display.";
    }

    std::cout << std::endl << std::endl;
}

//Return integer value of head node in queue (circular linked list). If statement included to prevent misuse/crashing
//outside of current program implementation.
Character* Queue::getFront() {
    //If queue is empty, inform user that queue is empty and return default value.
    if (isEmpty()) {
        std::cout << "Queue is empty. No value to return." << std::endl << std::endl;

        return nullptr;
    }
    //If queue is not empty, return integer value of head node.
    else {
        return head->fighter;
    }
}

//Add a node to tail of list. Takes QueueNode pointer to a pointer as head of queue.
void Queue::addFront(QueueNode* inputNode) {
    //If the queue is not empty, add node to front of queue.
    if (!isEmpty()) {
        QueueNode* tempEndNodePtr = head->prev;

        //Link to next node (current head Node)
        inputNode->next = head;

        //Link to previous node (nullptr)
        inputNode->prev = tempEndNodePtr;

        //Set previous head node previous pointer to new node
        head->prev = inputNode;

        //Set node at end of node to point to new front node
        tempEndNodePtr->next = inputNode;
    }
    //The queue is empty, add first node to queue.
    else {
        inputNode->next = inputNode;
        inputNode->prev = inputNode;
    }

    //Set head to new node
    head = inputNode;

}

//Search team queue passed as parameter for number of character types passed as parameter as string value.
//Return integer value for number of that character type present in team queue.
int Queue::numCharTeam(std::string inputCharType) {
    int numberCharacters = 1;
    //Check if queue is empty to avoid errors from empty pointers.
    if (!isEmpty()) {
        QueueNode* tempQueuePtr = head;

        //Loop through and fighters in queue and find number of occurrences of character type.
        do {
            //Compare character type with inputCharType and add 1
            if (tempQueuePtr->fighter->getCharType() == inputCharType) {
                numberCharacters++;
            }

            //Set temp pointer to next node in list
            tempQueuePtr = tempQueuePtr->next;
        } while (tempQueuePtr != head);
    }

    return numberCharacters;
}