#include "MagicalContainer.hpp"

MagicalContainer::MagicalContainer() : firstPrime(NULL), head(NULL), tail(NULL)
{
}
void MagicalContainer::addElement(int data)
{
    Node *newNode = new Node(data);
    newNode->getIsPrime() ? addPrimeElement(newNode) : addNonPrimeElement(newNode);
}

void MagicalContainer::addPrimeElement(Node *newNode)
{
    Node *lastNode = NULL;
    Node *lastPrime = NULL;
    Node *curr = head;
    while (curr)
    {
        if (newNode->getData() < curr->getData())
        {
            addToPrimesList(newNode, lastPrime);
            addToList(newNode, lastNode);
            return;
        }
        if (curr->getIsPrime())
            lastPrime = curr;
        lastNode = curr;
        curr = curr->getNext();
    }
    if (!firstPrime)
        firstPrime = newNode;
    addToList(newNode, lastNode);
    // nodes.emplace_back(newNode);
    // for (auto it = nodes.begin(); it != nodes.end(); ++it)
    // {
    //     if (newNode->getData() < (*it)->getData())
    //     {
    //         addToPrimesList(newNode, lastPrime);
    //         addToList(newNode, lastNode);
    //         nodes.insert(it, newNode);
    //         return;
    //     }
    //     if ((*it)->getIsPrime())
    //         lastPrime = *it;
    //     lastNode = *it;
    // }
}

void MagicalContainer::addNonPrimeElement(Node *newNode)
{
    Node *lastNode = NULL;
    Node *curr = head;
    while (curr)
    {
        if (newNode->getData() < curr->getData())
        {
            addToList(newNode, lastNode);
            return;
        }
        lastNode = curr;
        curr = curr->getNext();
    }
    addToList(newNode, lastNode);
    // for (auto it = nodes.begin(); it != nodes.end(); ++it)
    //     if (newNode->getData() < (*it)->getData())
    //     {
    //         nodes.insert(it, newNode);
    //         return;
    //     }
    // nodes.emplace_back(newNode);
}

void MagicalContainer::removeElement(int data)
{
    Node *curr = head;
    while (curr)
    {
        if (data == curr->getData())
        {
            if (curr->getIsPrime())
                removeFromPrimesList(curr);
            removeFromList(curr);
            delete curr;
            listSize--;
            return;
        }
        curr = curr->getNext();
    }
    listSize--;

    // for (auto it = nodes.begin(); it != nodes.end(); ++it)
    // {
    //     Node *curr = *it;
    //     if (data == curr->getData())
    //     {
    //         if (curr->getIsPrime())
    //         {
    //             Node *prev = curr->getPrevPrime();
    //             Node *next = curr->getNextPrime();
    //             if (prev)
    //                 prev->setNextPrime(next);
    //             if (next)
    //                 next->setPrevPrime(prev);
    //             if (firstPrime == curr)
    //                 firstPrime = next;
    //         }
    //         nodes.remove(*it);
    //         delete *it;
    //         return;
    //     }
    // }
}

void MagicalContainer::removeFromPrimesList(Node *curr)
{
    Node *prev = curr->getPrevPrime();
    Node *next = curr->getNextPrime();
    if (prev)
        prev->setNextPrime(next);
    if (next)
        next->setPrevPrime(prev);
    if (firstPrime == curr)
        firstPrime = next;
}
void MagicalContainer::removeFromList(Node *curr)
{
    Node *prev = curr->getPrev();
    Node *next = curr->getNext();
    if (prev)
        prev->setNext(next);
    if (next)
        next->setPrev(prev);
    if (head == curr)
        head = next;
    if (tail == curr)
        tail = prev;
}

void MagicalContainer::printList()
{
    Node *curr = head;
    cout << "HEAD";
    while (curr)
    {
        cout << " -> " << curr->getData();
        curr = curr->getNext();
    }
    cout << endl;
    // cout << "HEAD";
    // for (Node *n : nodes)
    // {
    //     cout << " -> " << n->getData();
    // }
    // cout << endl;
}

void MagicalContainer::printPrimes()
{
    Node *curr = firstPrime;
    cout << "PRIMES";
    while (curr)
    {
        cout << " -> " << curr->getData();
        curr = curr->getNextPrime();
    }
    cout << endl;
}

Node *MagicalContainer::getFirstPrime()
{
    return firstPrime;
}

// list<Node *>::const_iterator MagicalContainer::getBeginIterator() const
// {
//     return nodes.begin();
// }

// list<Node *>::const_iterator MagicalContainer::getEndIterator() const
// {
//     return nodes.end();
// }

// list<Node *> MagicalContainer::getNodes() const
// {
//     return nodes;
// }

MagicalContainer::~MagicalContainer()
{
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr;
        curr = curr->getNext();
        delete temp;
    }
    // for (auto it = nodes.begin(); it != nodes.end(); ++it)
    //     delete *it;
}

size_t MagicalContainer::size()
{
    return listSize;
    // return nodes.size();
}

void MagicalContainer::addToPrimesList(Node *newNode, Node *lastPrime)
{
    // there is a previous prime
    if (lastPrime)
    {
        Node *temp = lastPrime->getNextPrime();
        lastPrime->setNextPrime(newNode);
        newNode->setPrevPrime(lastPrime);
        newNode->setNextPrime(temp);
        if (temp)
            temp->setPrevPrime(newNode);
    }

    // newNode is the first prime
    else
    {
        if (firstPrime)
            firstPrime->setPrevPrime(newNode);
        newNode->setNextPrime(firstPrime);
        firstPrime = newNode;
    }
}

void MagicalContainer::addToList(Node *newNode, Node *lastNode)
{
    // there is a previous node
    if (lastNode)
    {
        Node *temp = lastNode->getNext();
        lastNode->setNext(newNode);
        newNode->setPrev(lastNode);
        newNode->setNext(temp);
        if (temp)
            temp->setPrev(newNode);
    }

    // newNode is the first node
    else
    {
        if (head)
            head->setPrev(newNode);
        newNode->setNext(head);
        head = newNode;
    }

    if (!newNode->getNext())
        tail = newNode;

    listSize++;
}
