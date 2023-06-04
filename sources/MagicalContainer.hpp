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
    class Iterator;
    class AscendingIterator;
    class PrimeIterator;
    class SideCrossIterator;
    MagicalContainer();
    void addElement(int data);
    void addPrimeElement(Node *newNode);
    void addNonPrimeElement(Node *newNode);
    void removeElement(int data);
    void printList();
    void printListAddresses();
    void printPrimes();
    size_t size() const;
    Node *getFirstPrime() const;
    Node *getHead() const;
    Node *getTail() const;
    ~MagicalContainer();
};

class MagicalContainer::Iterator
{
    Node *curr;
    const MagicalContainer &container;
    int type;

public:
    Iterator(const MagicalContainer &container, Node *curr, int type);
    virtual int operator*();
    Node *getCurr() const;
    const MagicalContainer &getContainer() const;
    void setCurr(Node *curr);
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    virtual bool operator<(const Iterator &other) const;
    virtual bool operator>(const Iterator &other) const;
    int getType() const;
    virtual Iterator &operator++() = 0;
};

class MagicalContainer::AscendingIterator : public MagicalContainer::Iterator
{
public:
    AscendingIterator(const MagicalContainer &container);
    AscendingIterator operator=(const AscendingIterator &other);
    AscendingIterator &operator++() override;
    AscendingIterator begin() const;
    AscendingIterator end() const;
    ~AscendingIterator() {}
};

class MagicalContainer::PrimeIterator : public MagicalContainer::Iterator
{
public:
    PrimeIterator(const MagicalContainer &container);
    PrimeIterator &operator++() override;
    PrimeIterator begin() const;
    PrimeIterator end() const;
    PrimeIterator operator=(const PrimeIterator &other);
    ~PrimeIterator() {}
};

class MagicalContainer::SideCrossIterator : public MagicalContainer::Iterator
{
    Node *last;
    int count;

public:
    SideCrossIterator(const MagicalContainer &container);
    SideCrossIterator &operator++() override;
    SideCrossIterator begin() const;
    SideCrossIterator end() const;
    SideCrossIterator operator=(const SideCrossIterator &other);
    int operator*() override;
    virtual bool operator<(const SideCrossIterator &other) const;
    ~SideCrossIterator() {}
};
