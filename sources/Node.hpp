#pragma once
#include <iostream>

using namespace std;

class Node
{
    int data;
    bool isPrime;
    Node* nextPrime;
    Node* prevPrime;
public:
    Node(int data);
    int getData();
    bool getIsPrime();
    void setNextPrime(Node* node);
    void setPrevPrime(Node* node);
    Node* getNextPrime();
    Node* getPrevPrime();
    bool operator==(const Node& other) const;
};