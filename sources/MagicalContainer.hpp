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
    class PrimeIterator;
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
    Node *getFirstPrime() const;
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
    Node *getCurr() const;
    const MagicalContainer &getContainer() const;
    void setCurr(Node *curr);
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    bool operator<(const Iterator &other) const;
    bool operator>(const Iterator &other) const;
    int getType() const;
    virtual Iterator &operator++() = 0;
    virtual Iterator &begin() const = 0;
    virtual Iterator &end() const = 0;
};

class MagicalContainer::AscendingIterator : public MagicalContainer::Iterator
{
public:
    AscendingIterator(const MagicalContainer &container);
    AscendingIterator operator=(const AscendingIterator &other);
    ~AscendingIterator() {}
    AscendingIterator &operator++() override;
    AscendingIterator &begin() const override;
    AscendingIterator &end() const override;
};

class MagicalContainer::PrimeIterator : public MagicalContainer::Iterator
{
public:
    PrimeIterator(const MagicalContainer &container);
    PrimeIterator &operator++() override;
    PrimeIterator &begin() const override;
    PrimeIterator &end() const override;
    PrimeIterator operator=(const PrimeIterator &other);
};

