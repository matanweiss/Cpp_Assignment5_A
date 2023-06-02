#include "Node.hpp"
#include "HelperFunctions.hpp"

Node::Node(int data) : data(data), nextPrime(NULL), prevPrime(NULL), isPrime(checkIsPrime(data))
{
}

int Node::getData() { return data; }
bool Node::getIsPrime() { return isPrime; }
void Node::setNextPrime(Node *node)
{
    nextPrime = node;
}
void Node::setPrevPrime(Node *node)
{
    prevPrime = node;
}
Node *Node::getNextPrime()
{
    return nextPrime;
}
Node *Node::getPrevPrime()
{
    return prevPrime;
}
bool Node::operator==(const Node &other) const
{
    return other.data == data;
}
