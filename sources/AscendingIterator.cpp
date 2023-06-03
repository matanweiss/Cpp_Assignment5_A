#include "MagicalContainer.hpp"

// MagicalContainer::AscendingIterator::AscendingIterator() : it(nodes.begin()) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : it(other.it), container(other.container) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &other, list<Node *>::const_iterator it) : it(it), container(other) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &other) : container(other), it(other.getBeginIterator()) {}

int MagicalContainer::AscendingIterator ::operator*() const
{
    return (*it)->getData();
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator ::operator++()
{
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
