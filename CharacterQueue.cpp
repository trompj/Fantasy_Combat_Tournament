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

#include "CharacterQueue.hpp"

//Default constructor sets head to nullptr for empty queue.
CharacterQueue::CharacterQueue(){
    head = nullptr;
}

//Destructor to free all allocated memory
CharacterQueue::~CharacterQueue(){
    //Loop through list and free allocated memory for nodes.
    while (head != nullptr) {
        removeFront();
    }
}

//Validate integer input from min through max parameters passed to function
int CharacterQueue::validateInputRangeInt (int min, int max) {
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

//Checks to see if queue is empty
bool CharacterQueue::isEmpty(QueueNode* inputQueueHead) {
    //Set to true as default
    bool queueEmpty = true;

    //If queue is not empty, set bool value to false.
    if (inputQueueHead != nullptr) {
        queueEmpty = false;
    }

    return queueEmpty;
}

//Add new node to end of list. Takes int value as parameter to set node value to.
void CharacterQueue::addBack(Character* inputChar, QueueNode** inputQueueHead) {
    //Create new node that does not point to anything and holds integer value.
    QueueNode* newNode = new QueueNode;

    //Set value according to integer passed as parameter.
    newNode->combatCharacter = inputChar;

    //If queue is empty, add QueueNode as if list is empty.
    if (isEmpty(*inputQueueHead)) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *inputQueueHead = newNode;
    }
        //If queue is not empty, add QueueNode to end of circular list.
    else {
        //Declare/set tempPtrLast to last node in list.
        QueueNode* tempPtrLast = (*inputQueueHead)->prev;

        //Set last node in queue to point to newNode.
        tempPtrLast->next = newNode;

        //Set newNode to point to previous last node and to the first node in queue.
        newNode->prev = tempPtrLast;
        newNode->next = *inputQueueHead;

        //Set first node previous to point to newNode being placed at end.
        (*inputQueueHead)->prev = newNode;
    }

    //printQueue(*inputQueueHead);
}

//Delete node from front of list
void CharacterQueue::removeFront() {
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

        delete tempPtrFront;
    }
}

/*
//Traverse list and print out integer values to screen stored in each node for user
void CharacterQueue::printQueue() {
    //Check list to see if it is empty, if it is, inform user that it is empty
    if (!isEmpty()) {
        std::cout << "Your queue is: ";

        QueueNode* temp = head;
        //Loop through and print integer value held in each QueueNode in circular list.
        do {
            //Print value of temp pointer
            std::cout << temp->val << " ";

            //Set temp pointer to next node in list
            temp = temp->next;

        } while (temp != head);
    }

    //List is empty, so inform user that it is empty
    else {
        std::cout << "The queue is empty. No contents to display.";
    }

    std::cout << std::endl << std::endl;
}*/

//Return integer value of head node in queue (circular linked list). If statement included to prevent misuse/crashing
//outside of current program implementation.
Character* CharacterQueue::getFront() {
    return head->combatCharacter;
}

/*
//Run double linked list menu and list manipulation
void CharacterQueue::queueRunMenu() {
    int menuSelection = 0;

    //Loop until user elects to quit program
    do {
        menuSelection = userMenu();

        //Switch for menu selection
        switch (menuSelection){
            //Add node/value to back of queue
            case 1: {
                int userIntInput = 0;

                //Request integer value from user for new node and validate.
                userIntInput = intInputRequest();

                //Add node to end of queue
                addBack(userIntInput);

                break;
            }
            //Display the front node value
            case 2: {
                int headVal = 0;

                //If queue is not empty, return value of head node.
                if (!isEmpty()) {
                    //Returns integer value of head node in queue.
                    headVal = getFront();

                    //Output value of first node in queue.
                    std::cout << "The first node value is: " << headVal << std::endl << std::endl;
                }
                //If queue is empty, inform user that queue is empty.
                else {
                    std::cout << "Queue is empty. No value to return." << std::endl << std::endl;
                }

                break;
            }
            //Delete node from front of list
            case 3: {
                //Remove first node
                removeFront();

                break;
            }
            //Display the queue's contents to user
            case 4: {
                printQueue();

                break;
            }
        }
    } while (menuSelection != 5);
}*/