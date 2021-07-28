//
// Created by Kennedy Onyema-willys on 7/12/21.
//
#include <iostream>
#include "node_class.h"

Node::Node()
{
    next = nullptr;
}

void Node::setLine(std::string l)
{
    line = l;
}

void Node::setNext(std::shared_ptr<Node> nPtr)
{
    next = nPtr;
}

std::string Node::getLine()
{
    return line;
    //return line
}

std::shared_ptr<Node> Node::getNext()
{
    return next;
    //return next.
}

