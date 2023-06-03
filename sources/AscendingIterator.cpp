#include "AscendingIterator.hpp"

// // MagicalContainer::AscendingIterator::AscendingIterator() : it(nodes.begin()) {}

// MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : it(other.it), container(other.container) {}

// MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &other, list<Node *>::const_iterator it) : it(it), container(other) {}

AscendingIterator::AscendingIterator(const MagicalContainer &container) : Iterator(container)
{
    setCurr(container.getHead());
}

// int MagicalContainer::AscendingIterator ::operator*() const
// {
//     return (*it)->getData();
// }

AscendingIterator &AscendingIterator ::operator++()
{
    if (!getCurr())
        throw runtime_error("Iterator has aleady ended");
    setCurr(getCurr()->getNext());
    return *this;
}

MagicalContainer::Iterator *AscendingIterator::begin() const
{
    return new AscendingIterator(getContainer());
}

MagicalContainer::Iterator *AscendingIterator::end() const
{
    AscendingIterator *iter = new AscendingIterator(getContainer());
    iter->setCurr(NULL);
    return iter;
}

// MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
// {
//     if (this != &other)
//         throw runtime_error("cannot assign from different cotainer");
//     it = other.it;
//     return *this;
// }

// bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &other) const
// {
//     return it == other.getIterator();
// }

// bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) const
// {
//     return it != other.getIterator();
// }

// list<Node *>::const_iterator MagicalContainer::AscendingIterator::getIterator() const
// {
//     return it;
// }

// bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
// {
//     return (*it)->getData() < (*other.getIterator())->getData();
// }

// bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
// {
//     return !(*this < other || *this == other);
// }
