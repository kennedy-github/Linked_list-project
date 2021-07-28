//
// Created by Kennedy Onyema-willys on 7/12/21.
//

#ifndef LAB_3_KENNEDY_ONYEMA_WILLYS_LINKEDLIST_CLASS_H
#define LAB_3_KENNEDY_ONYEMA_WILLYS_LINKEDLIST_CLASS_H
#include <iostream>
#include <memory>
#include <vector>
#include "node_class.h"

class LinkedList                  //class
{
private:
    std::shared_ptr<Node> headptr;            //private members
    int numItems;
public:
    LinkedList();            //public members
    int getNumItems();
    int checkDuplicates(std::string v);
    void addNode(std::string v);
    std::vector<std::string> toVector();
};
#endif //LAB_3_KENNEDY_ONYEMA_WILLYS_LINKEDLIST_CLASS_H
