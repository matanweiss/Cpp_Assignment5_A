#include "MagicalContainer.hpp"

MagicalContainer::Iterator::Iterator(const MagicalContainer &container, Node *curr, int type) : container(container), curr(curr), type(type)
{
}

int MagicalContainer::Iterator::operator*()
{
    if (!curr)
        throw runtime_error("Element is NULL");
    return curr->getData();
}

bool MagicalContainer::Iterator::operator==(const Iterator &other) const
{
    int thisValue = 0;
    int otherValue = 0;
    if (curr)
        thisValue = curr->getData();
    if (other.curr)
        otherValue = other.curr->getData();
    return thisValue == otherValue;
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

Node *MagicalContainer::Iterator::getCurr() const
{
    return curr;
}

void MagicalContainer::Iterator::setCurr(Node *curr)
{
    this->curr = curr;
}

const MagicalContainer &MagicalContainer::Iterator::getContainer() const
{
    return container;
}

    int MagicalContainer::Iterator::getType() const{
        return type;
    }