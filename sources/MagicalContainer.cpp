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
                if(firstPrime)
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
        if (data == (*it)->getData())
        {
            nodes.remove(new Node(data));
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

Node *MagicalContainer::getFirstPrime()
{
    return firstPrime;
}

MagicalContainer::~MagicalContainer()
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
        delete *it;
}
