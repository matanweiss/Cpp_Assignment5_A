#include "MagicalContainer.hpp"

MagicalContainer::MagicalContainer()
{
}
void MagicalContainer::addElement(int data)
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        if (data < it->getData())
        {
            nodes.insert(it, Node(data));
            return;
        }
    }
    nodes.emplace_back(Node(data));
}

void MagicalContainer::printList()
{
    cout << "HEAD";
    for (Node n : nodes)
    {
        cout << " -> " << n.getData();
    }
    cout << endl;
}