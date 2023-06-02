#pragma once
#include "Node.hpp"
#include <list>
#include <iterator>
namespace ariel
{
};

class MagicalContainer
{
    list<Node> nodes;

public:
    MagicalContainer();
    void addElement(int data);
    void printList();
    // class AscendingIterator<Node*>
    // {
    //     Node* current;

    // };
};