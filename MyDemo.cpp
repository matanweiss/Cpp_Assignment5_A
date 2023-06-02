#include <iostream>
#include "sources/MagicalContainer.hpp"
using namespace ariel;
int main()
{
    // Create a MagicalContainer and add some elements
    Node a(4);
    Node b(5);
    Node c(4);
    bool r = a==b;
    bool r2 = a==c;
    cout << r<< endl;
    cout << r2 << endl;

    MagicalContainer container;
    if(container.getFirstPrime())
        cout << "there is a first prime" << endl;
    container.addElement(17);
    if(container.getFirstPrime())
        cout << "there is a first prime" << endl;
    cout << container.getFirstPrime()->getData() << endl;
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    container.printList();
    // container.removeElement(3);
    // container.removeElement(34); // number not exits
    // container.printList();

    return 0;
}
