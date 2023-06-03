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
    container.printPrimes();
    container.removeElement(17);
    container.printList();
    container.printPrimes();

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;
    // container.removeElement(34); // number not exits
    // container.printList();

    return 0;
}
