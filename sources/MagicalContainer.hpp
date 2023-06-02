#pragma once
#include "Node.hpp"
#include "HelperFunctions.hpp"
#include <list>
#include <iterator>
namespace ariel
{
};

class MagicalContainer
{
    list<Node*> nodes;
    Node* firstPrime;
public:
    MagicalContainer();
    void addElement(int data);
    void addPrimeElement(Node* newNode);
    void addNonPrimeElement(Node* newNode);
    void removeElement(int data);
    void printList();
    Node* getFirstPrime();
    ~MagicalContainer();
    // class AscendingIterator<Node*>
    // {
    //     Node* current;

    // };
};