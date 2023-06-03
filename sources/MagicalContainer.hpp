#pragma once
#include "Node.hpp"
#include <list>
#include <iterator>

#define ASCENDING 1
#define CROSS 2
#define PRIME 3

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
    // class PrimeIterator;
    class Iterator;
    class AscendingIterator;
    MagicalContainer();
    void addElement(int data);
    void addPrimeElement(Node *newNode);
    void addNonPrimeElement(Node *newNode);
    void removeElement(int data);
    void printList();
    void printPrimes();
    size_t size();
    Node *getFirstPrime();
    Node *getHead() const;
    ~MagicalContainer();
};

class MagicalContainer::Iterator
{
    Node *curr;
    const MagicalContainer &container;
    int type;

public:
    Iterator(const MagicalContainer &container, Node *curr, int type);
    int operator*();
    // virtual Iterator &operator++() = 0;
    // virtual const Iterator &begin() const = 0;
    // virtual const Iterator &end() const = 0;
    Node *getCurr() const;
    const MagicalContainer &getContainer() const;
    void setCurr(Node *curr);
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    bool operator<(const Iterator &other) const;
    bool operator>(const Iterator &other) const;
};

class MagicalContainer::AscendingIterator : public MagicalContainer::Iterator
{
public:
    AscendingIterator(const MagicalContainer &container);
    AscendingIterator &operator++();
    AscendingIterator begin() const;
    AscendingIterator end() const;
    // Iterator &operator++() override;
    // const Iterator &begin() const override;
    // const Iterator &end() const override;
    AscendingIterator operator=(const AscendingIterator &other);
    ~AscendingIterator() {}
};

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
