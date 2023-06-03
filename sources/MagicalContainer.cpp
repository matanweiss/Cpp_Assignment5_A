#include "MagicalContainer.hpp"

MagicalContainer::MagicalContainer() : firstPrime(NULL)
{
}
void MagicalContainer::addElement(int data)
{
    Node *newNode = new Node(data);
    newNode->getIsPrime() ? addPrimeElement(newNode) : addNonPrimeElement(newNode);
}

void MagicalContainer::addPrimeElement(Node *newNode)
{
    Node *lastPrime = NULL;
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        if (newNode->getData() < (*it)->getData())
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
            nodes.insert(it, newNode);
            return;
        }
        if ((*it)->getIsPrime())
            lastPrime = *it;
    }
    if (!firstPrime)
        firstPrime = newNode;
    nodes.emplace_back(newNode);
}

void MagicalContainer::addNonPrimeElement(Node *newNode)
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
        if (newNode->getData() < (*it)->getData())
        {
            nodes.insert(it, newNode);
            return;
        }
    nodes.emplace_back(newNode);
}

void MagicalContainer::removeElement(int data)
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        Node *curr = *it;
        if (data == curr->getData())
        {
            if (curr->getIsPrime())
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
            nodes.remove(*it);
            return;
        }
    }
}

void MagicalContainer::printList()
{
    cout << "HEAD";
    for (Node *n : nodes)
    {
        cout << " -> " << n->getData();
    }
    cout << endl;
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

list<Node *> MagicalContainer::getNodes()
{
    return nodes;
}

MagicalContainer::~MagicalContainer()
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
        delete *it;
}

size_t MagicalContainer::size()
{
    return nodes.size();
}

int MagicalContainer::AscendingIterator ::operator*() const
{
    return (*it)->getData();
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator ::operator++()
{
    ++it;
    return *this;
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer container) : it(container.getNodes().begin()), container(&container) {}

list<Node *>::iterator MagicalContainer::AscendingIterator::begin()
{
    return container->getNodes().begin();
}

list<Node *>::iterator MagicalContainer::AscendingIterator::end()
{
    return container->getNodes().end();
}

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &other) const
{
    return **this == *other;
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) const
{
    return **this != *other;
}