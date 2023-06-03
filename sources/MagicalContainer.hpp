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
    class AscendingIterator;
    class PrimeIterator;
    MagicalContainer();
    void addElement(int data);
    void addPrimeElement(Node *newNode);
    void addNonPrimeElement(Node *newNode);
    void removeElement(int data);
    void printList();
    void printPrimes();
    size_t size();
    Node *getFirstPrime();
    list<Node *>::const_iterator getBeginIterator() const;
    list<Node *>::const_iterator getEndIterator() const;
    list<Node *> getNodes() const;
    ~MagicalContainer();
};

class MagicalContainer::AscendingIterator
{
    list<Node *>::const_iterator it;
    const MagicalContainer &container;

public:
    // AscendingIterator();
    AscendingIterator(const AscendingIterator &other);
    AscendingIterator(const MagicalContainer &other);
    AscendingIterator(const MagicalContainer &other, list<Node *>::const_iterator it);
    int operator*() const;
    AscendingIterator &operator++();
    AscendingIterator begin();
    AscendingIterator end();
    AscendingIterator operator=(const AscendingIterator &other);
    bool operator==(const AscendingIterator &other) const;
    bool operator!=(const AscendingIterator &other) const;
    list<Node *>::const_iterator getIterator() const;
    bool operator<(const AscendingIterator &other) const;
    bool operator>(const AscendingIterator &other) const;
};

class MagicalContainer::PrimeIterator : public MagicalContainer::AscendingIterator{
    Node* curr;
};
