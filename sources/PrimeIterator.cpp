// #include "MagicalContainer.hpp"

// MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : container(container), curr(container.firstPrime)
// {
// }

// int MagicalContainer::PrimeIterator::operator*() const
// {
//     return curr->getData();
// }

// MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
// {
//     if (!curr)
//         throw runtime_error("Iterator has aleady ended");
//     curr = curr->getNextPrime();
//     return *this;
// }

// MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
// {
//     return PrimeIterator(container);
// }

// MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
// {
//     PrimeIterator res(container);
//     res.curr = NULL;
//     return res;
// }