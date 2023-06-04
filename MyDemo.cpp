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
    cout << "tail: " << container.getTail()->getData() << endl;
    container.addElement(2);
    cout << "tail: " << container.getTail()->getData() << endl;
    container.addElement(25);
    cout << "tail: " << container.getTail()->getData() << endl;
    container.addElement(9);
    cout << "tail: " << container.getTail()->getData() << endl;
    container.addElement(3);
    cout << "tail: " << container.getTail()->getData() << endl;
    container.printList();
    container.printPrimes();
    container.removeElement(2);
    container.addElement(29);
    container.printList();
    container.printPrimes();
    // container.addElement(17);
    // container.removeElement(34); // number not exits

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        std::cout << *it << ' '; // 2 3 9 17 25
    }
    std::cout << std::endl;

    MagicalContainer::AscendingIterator ascendingIterator1(container);
    MagicalContainer::AscendingIterator ascendingIterator2(container);
    ++ascendingIterator2;
    ++ascendingIterator2;
    if (ascendingIterator1 < ascendingIterator2)
        cout << "OK" << endl;
    if (!(ascendingIterator1 > ascendingIterator2))
        cout << "OK" << endl;
    ++ascendingIterator1;
    if (ascendingIterator1 < ascendingIterator2)
        cout << "OK" << endl;
    ++ascendingIterator1;
    if (!(ascendingIterator1 < ascendingIterator2))
        cout << "OK" << endl;
    if (ascendingIterator1 == ascendingIterator2)
        cout << "OK" << endl;
    ++ascendingIterator1;
    if (ascendingIterator1 != ascendingIterator2)
        cout << "OK" << endl;

    container.printList();
    container.printPrimes();

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
    {
        std::cout << *it << ' '; // 2 3 17
    }
    std::cout << std::endl;

    MagicalContainer::PrimeIterator primeIterator1(container);
    MagicalContainer::PrimeIterator primeIterator2(container);
    ++primeIterator2;
    ++primeIterator2;
    if (primeIterator1 < primeIterator2)
        cout << "OK" << endl;
    if (!(primeIterator1 > primeIterator2))
        cout << "OK" << endl;
    ++primeIterator1;
    if (primeIterator1 < primeIterator2)
        cout << "OK" << endl;
    ++primeIterator1;
    if (!(primeIterator1 < primeIterator2))
        cout << "OK" << endl;
    if (primeIterator1 == primeIterator2)
        cout << "OK" << endl;
    ++primeIterator1;
    if (primeIterator1 != primeIterator2)
        cout << "OK" << endl;

    container.printList();
    container.printPrimes();

    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
    {
        std::cout << *it << ' '; // 2 25 3 17 9
    }
    std::cout << std::endl;

    MagicalContainer::SideCrossIterator SideCrossIterator1(container);
    MagicalContainer::SideCrossIterator SideCrossIterator2(container);
    ++SideCrossIterator2;
    ++SideCrossIterator2;
    if (SideCrossIterator1 < SideCrossIterator2)
        cout << "OK1" << endl;
    if (!(SideCrossIterator1 > SideCrossIterator2))
        cout << "OK2" << endl;
    ++SideCrossIterator1;
    if (SideCrossIterator1 < SideCrossIterator2)
        cout << "OK3" << endl;
    ++SideCrossIterator1;
    if (!(SideCrossIterator1 < SideCrossIterator2))
        cout << "OK4" << endl;
    if (SideCrossIterator1 == SideCrossIterator2)
        cout << "OK5" << endl;
    ++SideCrossIterator1;
    if (SideCrossIterator1 != SideCrossIterator2)
        cout << "OK6" << endl;

    container.printList();
    container.printPrimes();

    return 0;
}
