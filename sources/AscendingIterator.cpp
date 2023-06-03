#include "MagicalContainer.hpp"

// MagicalContainer::AscendingIterator::AscendingIterator() : it(nodes.begin()) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : it(other.it), container(other.container) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &other, list<Node *>::const_iterator it) : it(it), container(other) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container) : container(container), it(container.getBeginIterator()) {}

int MagicalContainer::AscendingIterator ::operator*() const
{
    return (*it)->getData();
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator ::operator++()
{
    if (!*it)
        throw runtime_error("Iterator has aleady ended");
    ++it;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return AscendingIterator(container, container.getEndIterator());
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
        throw runtime_error("cannot assign from different cotainer");
    it = other.it;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &other) const
{
    return it == other.getIterator();
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) const
{
    return it != other.getIterator();
}

list<Node *>::const_iterator MagicalContainer::AscendingIterator::getIterator() const
{
    return it;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return (*it)->getData() < (*other.getIterator())->getData();
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return !(*this < other || *this == other);
}
