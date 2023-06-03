#pragma once
#include "MagicalContainer.hpp"

class AscendingIterator : public MagicalContainer::Iterator
{
    AscendingIterator(const MagicalContainer &container);
    AscendingIterator &operator++() override;
    Iterator *begin() const override;
    Iterator *end() const override;
    AscendingIterator operator=(const AscendingIterator &other);
    ~AscendingIterator() {}
};