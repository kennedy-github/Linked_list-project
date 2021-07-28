//
// Created by Kennedy Onyema-willys on 7/12/21.
//

#include <iostream>
#include "LinkedList_class.h"
#include "node_class.h"

//Linked list method definition
LinkedList::LinkedList()
{
    numItems = 0;           //set number of items to zero.
}//end Linked list()

int LinkedList::getNumItems()
{
    return numItems;        //return number of items
}//end numItems

int LinkedList::checkDuplicates(std::string v)        //Check for duplicates on the vector
{
    std::string value = v;
    int result = 1;

    for (int i = 0; i < numItems; i++)
    {
        if (value  == toVector()[i])       //compare with the vector.
        {
            i = numItems;
            result = 0;
        }

    }

return result;
} //end Duplicates

void LinkedList::addNode(std::string v)           //addNode
{
    std::string value = v;


    std::shared_ptr<Node> newNodePtr = std::make_shared<Node>();
    newNodePtr->setLine(value);

    if (checkDuplicates(value) == 1)           //Check duplicate status
    {
        if (!headptr)        //If list is empty
        {
            headptr = newNodePtr;
        }
        else
        {
            if (headptr->getLine() > newNodePtr->getLine())          //If only one pointer exists
            {
                newNodePtr->setNext(headptr);
                headptr = newNodePtr;
            }
            else   //Other complicated cases
            {
                std::shared_ptr<Node> currPtr = headptr;
                for(int i = 0; i < numItems; i++)          //Loop through the list
                {

                    if ( currPtr->getNext() != nullptr && newNodePtr->getLine() > currPtr->getNext()->getLine())
                    //if next pointer after current isn't null and newNode is greater than the next pointer
                    {
                        currPtr = currPtr->getNext();
                    }
                    else            //inst new Node to match alphabetically
                    {
                        std::shared_ptr<Node> swapPtr = currPtr->getNext();
                        currPtr->setNext(newNodePtr);
                        newNodePtr->setNext(swapPtr);
                        i = numItems;
                    }
                }
            }

        }

        newNodePtr = nullptr;


        numItems++;         //increment number of items.

    }


}

std::vector<std::string> LinkedList::toVector()       //Vector for displaying list contents
{

    std::shared_ptr<Node> currPtr = headptr;

    std::vector<std::string> bagContents;
    for (int i = 0; i < numItems; i++)         //Loop through
    {
        currPtr->getLine();
        std::string value = currPtr->getLine();
        bagContents.push_back(value);           //Push back items into vector.
        currPtr = currPtr->getNext();
    }
    currPtr = nullptr;


    return bagContents;          //return Vector.


}