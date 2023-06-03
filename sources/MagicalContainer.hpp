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
    list<Node *> nodes;
    Node *firstPrime;

public:
    MagicalContainer();
    void addElement(int data);
    void addPrimeElement(Node *newNode);
    void addNonPrimeElement(Node *newNode);
    void removeElement(int data);
    void printList();
    void printPrimes();
    size_t size();
    Node *getFirstPrime();
    list<Node *> getNodes();
    ~MagicalContainer();
    class AscendingIterator
    {
        MagicalContainer *container;
        list<Node *>::iterator it;

    public:
        // default constructor
        AscendingIterator(MagicalContainer container);
        int operator*() const;
        MagicalContainer::AscendingIterator &operator++();
        list<Node *>::iterator begin();
        list<Node *>::iterator end();
        bool operator==(const MagicalContainer::AscendingIterator &other) const;
        bool operator!=(const MagicalContainer::AscendingIterator &other) const;
    };
};