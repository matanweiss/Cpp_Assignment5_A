#include "MagicalContainer.hpp"

MagicalContainer::Iterator::Iterator(const MagicalContainer &container) : container(container)
{
}

int MagicalContainer::Iterator::operator*() const
{
    return curr->getData();
}

bool MagicalContainer::Iterator::operator==(const Iterator &other) const
{
    return curr->getData() == other.curr->getData();
}

bool MagicalContainer::Iterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::Iterator::operator<(const Iterator &other) const
{
    return curr->getData() < other.curr->getData();
}

bool MagicalContainer::Iterator::operator>(const Iterator &other) const
{
    return !(*this < other || *this == other);
}

// MagicalContainer::Iterator &MagicalContainer::Iterator::operator++()
// {
//     if (!curr)
//         throw runtime_error("Iterator has already reached the end");
//     curr = curr->getNext();
//     return *this;
// }

// MagicalContainer::Iterator MagicalContainer::Iterator::operator=(const Iterator &other)
// {
//     if (this != &other)
//         throw runtime_error("cannot assign from an iterator a different container");
//     curr = other.curr;
//     return *this;
// }