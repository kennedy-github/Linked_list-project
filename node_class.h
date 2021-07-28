//
// Created by Kennedy Onyema-willys on 7/12/21.
//

#ifndef LAB_3_KENNEDY_ONYEMA_WILLYS_NODE_CLASS_H
#define LAB_3_KENNEDY_ONYEMA_WILLYS_NODE_CLASS_H
#include <iostream>
#include <memory>

class Node             //class
{
private:
    std::string line;              //Private members
    std::shared_ptr<Node> next;
public:
    Node();                       //Public Members
    void setLine(std::string);
    void setNext(std::shared_ptr<Node>);
    std::string getLine();
    std::shared_ptr<Node> getNext();
};
#endif //LAB_3_KENNEDY_ONYEMA_WILLYS_NODE_CLASS_H
