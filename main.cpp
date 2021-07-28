//Dev_Name: Kennedy Onyema-Willys
//Github: kennedy-github (github.com/kennedy-github)
//Program Name: Linked List
//Date: (07-12-2021)
//Description: Program is Linked list that reads contents of a text file chosen by the client or user, then creates a
//             linked list out of it. Program rejects empty lines and duplicates. Display of linked list is automatic.


#include <iostream>
#include <fstream>
#include "node_class.h"
#include "LinkedList_class.h"

/******************************************************************************/
// Function:  integerInputValidator
// Inputs:    unvalidated user input
// Outputs:   validated user input
// Purpose:    This function validates user input to
//             avoid wrong or invalid input that could crash the program.
/******************************************************************************/
int integerInputValidator(int input)
{
    // input validator


    while(!(std::cin >> input))      // checks input
    {
        std::cout << "[Error:] Invalid Input. Please enter an integer: ";

        std::cin.clear();   // clears wrong input

        std::cin.ignore(123, '\n');     //input buffer

    }
    return input;             // returns validated input.
}

/**************************************************/
// Function: getOption
// Inputs:  NIL
// Outputs: A valid user input.
// Purpose: This functions displays the main menu,
//          takes users input and validates it.
/**************************************************/
int getOption()
{
    int option, input;

    std::cout << "\n===Menu===\n";
    std::cout << "[1.] Execute.\n"
              << "[2.] Quit.\n";
    std::cout << "Enter option: ";
    option = integerInputValidator(input);          // Validates input
    return option;
}

/******************************************************************************/
// Function:  execute
// Inputs:    unvalidated user input
// Outputs:   validated user input
// Purpose:   This function essentially operates as a standalone function so the
//            user can quit the program easily from main.
/******************************************************************************/
void execute()
{
    Node Node;
    LinkedList LinkedList;
    std::string value, fileName;           //Variables
    int lineCounter = 0;

    std::cout << "Enter file name. Text files Only. \n";             //Warning messages
    std::cout << "[Warning:]Do not include extension. \n ";
    std::cout << "File name: ";
    std::cin >> fileName;

    fileName = fileName + ".txt";
    std::cout << "[File Name: ]" << fileName << "\n\n";


    std::ifstream file(fileName);
    if (file.is_open()) // Checks if file is open
    {
       while(getline(file, value))
       {
           lineCounter++;         //Updates LineCounter
           LinkedList.addNode(value);
       }
    }
    file.close();         //Close file just for precaution

    std::cout << "[Number of lines in file:] " << lineCounter << std::endl;

    std::vector<std::string> ListContents = LinkedList.toVector();        // creates vector copy of linked list
    int numberOfEntries = (int)ListContents.size();
    std::cout << "\n ==[LINKED LIST:]== \n";
    for (int i = 0; i < numberOfEntries; i++)         // displays contents using loop
    {
        std::cout << i+1 << "] " << ListContents[i] << std::endl;
    }

    std::cout << "\n\n[Number of lines in Vector:] " << numberOfEntries << std::endl;
    std::cout << "[Number of lines rejected including duplicates:] " << lineCounter - numberOfEntries << std::endl;

}


int main()
{
    int choice;

    choice = getOption();
    while (choice != 2)         //Case structure.
    {
        switch (choice)
        {
            case 1:
                execute();
                break;

        }
        choice = getOption();
    }
    return 0;
}

