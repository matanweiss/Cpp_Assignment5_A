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
    size_t listSize;
    Node *head;
    Node *tail;
    Node *firstPrime;
    void addToPrimesList(Node *newNode, Node *lastPrime);
    void addToList(Node *newNode, Node *lastNode);
    void removeFromPrimesList(Node *curr);
    void removeFromList(Node *curr);

public:
    // class AscendingIterator;
    // class PrimeIterator;
    class Iterator;
    MagicalContainer();
    void addElement(int data);
    void addPrimeElement(Node *newNode);
    void addNonPrimeElement(Node *newNode);
    void removeElement(int data);
    void printList();
    void printPrimes();
    size_t size();
    Node *getFirstPrime();
    ~MagicalContainer();
};

class MagicalContainer::Iterator
{
    Node *curr;
    const MagicalContainer &container;

public:
    Iterator(const MagicalContainer &container);
    int operator*() const;
    virtual Iterator &operator++() = 0;
    virtual Iterator &begin() const = 0;
    virtual Iterator &end() const = 0;
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    bool operator<(const Iterator &other) const;
    bool operator>(const Iterator &other) const;
};

// class MagicalContainer::AscendingIterator
// {
//     list<Node *>::const_iterator it;
//     const MagicalContainer &container;

// public:
//     // AscendingIterator();
//     AscendingIterator(const AscendingIterator &other);
//     AscendingIterator(const MagicalContainer &container);
//     AscendingIterator(const MagicalContainer &other, list<Node *>::const_iterator it);
//     int operator*() const;
//     AscendingIterator &operator++();
//     AscendingIterator begin();
//     AscendingIterator end();
//     AscendingIterator operator=(const AscendingIterator &other);
//     bool operator==(const AscendingIterator &other) const;
//     bool operator!=(const AscendingIterator &other) const;
//     list<Node *>::const_iterator getIterator() const;
//     bool operator<(const AscendingIterator &other) const;
//     bool operator>(const AscendingIterator &other) const;
// };

// class MagicalContainer::PrimeIterator
// {
//     Node *curr;
//     const MagicalContainer &container;
//     PrimeIterator(const MagicalContainer &container);
//     int operator*() const;
//     PrimeIterator &operator++();
//     PrimeIterator begin();
//     PrimeIterator end();
// };
