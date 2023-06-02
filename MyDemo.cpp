#include <iostream>
#include "sources/MagicalContainer.hpp"
using namespace ariel;
int main()
{
    // Create a MagicalContainer and add some elements
    Node a(4);
    Node b(5);
    Node c(4);
    bool r = a == b;
    bool r2 = a == c;
    cout << r << endl;
    cout << r2 << endl;

    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    container.printList();
    Node *curr = container.getFirstPrime();
    cout << "PRIMES";
    while (curr)
    {
        cout << "->" << curr->getData();
        curr = curr->getNextPrime();
    }
    cout << endl;

    // container.removeElement(3);
    // container.removeElement(34); // number not exits
    // container.printList();

    return 0;
}
