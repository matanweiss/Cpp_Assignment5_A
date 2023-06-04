#include "doctest.h"
#include "MagicalContainer.hpp"

TEST_CASE("MagicalContainer")
{
    MagicalContainer container;
    SUBCASE("Adding elements")
    {
        CHECK_NOTHROW(container.addElement(4));
        CHECK_NOTHROW(container.addElement(1));
        CHECK_NOTHROW(container.addElement(2));
        CHECK_NOTHROW(container.addElement(8));
        CHECK_NOTHROW(container.addElement(5));
        CHECK_NOTHROW(container.addElement(9));
    }

    // SUBCASE("adding the same element multiple times"){
    // CHECK_NOTHROW(container.addElement(5));
    // CHECK_NOTHROW(container.addElement(1));
    // CHECK_NOTHROW(container.addElement(1));
    // CHECK_NOTHROW(container.addElement(1));
    // }

    SUBCASE("removing existing elements")
    {
        CHECK_NOTHROW(container.removeElement(2));
        CHECK_NOTHROW(container.removeElement(27));
        CHECK_NOTHROW(container.removeElement(1));
    }

    SUBCASE("removing non-existing elements")
    {
        CHECK_NOTHROW(container.removeElement(2));
        CHECK_NOTHROW(container.removeElement(42));
        CHECK_NOTHROW(container.removeElement(8));
        CHECK_NOTHROW(container.removeElement(8));
    }

    SUBCASE("container size method")
    {
        CHECK(container.size() == 0);
        CHECK_NOTHROW(container.addElement(4));
        CHECK_NOTHROW(container.addElement(1));
        CHECK_NOTHROW(container.addElement(2));
        CHECK_NOTHROW(container.addElement(8));
        CHECK_NOTHROW(container.addElement(5));
        CHECK_NOTHROW(container.addElement(9));
        CHECK(container.size() == 6);
        CHECK_NOTHROW(container.removeElement(8));
        CHECK(container.size() == 5);
        CHECK_NOTHROW(container.removeElement(4));
        CHECK_NOTHROW(container.removeElement(1));
        CHECK_NOTHROW(container.removeElement(2));
        CHECK_NOTHROW(container.removeElement(5));
        CHECK_NOTHROW(container.removeElement(9));
        CHECK(container.size() == 0);
    }
}

TEST_CASE("AscendingIterator")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(4));
    CHECK_NOTHROW(container.addElement(1));
    CHECK_NOTHROW(container.addElement(11));
    CHECK_NOTHROW(container.addElement(7));
    CHECK_NOTHROW(container.addElement(18));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(8));
    CHECK_NOTHROW(container.addElement(5));

    SUBCASE("order of iterator")
    {
        MagicalContainer::AscendingIterator ascendingIterator(container);
        CHECK(*ascendingIterator == 1);
        ++ascendingIterator;
        CHECK(*ascendingIterator == 2);
        ++ascendingIterator;
        CHECK(*ascendingIterator == 4);
        ++ascendingIterator;
        CHECK(*ascendingIterator == 5);
        ++ascendingIterator;
        CHECK(*ascendingIterator == 7);
        ++ascendingIterator;
        CHECK(*ascendingIterator == 8);
        ++ascendingIterator;
        CHECK(*ascendingIterator == 11);
        ++ascendingIterator;
        CHECK(*ascendingIterator == 18);
        ++ascendingIterator;
        CHECK_THROWS(*ascendingIterator);
    }

    // SUBCASE("GT and LT operators"){
    //     MagicalContainer::AscendingIterator ascendingIterator1(container);
    //     MagicalContainer::AscendingIterator ascendingIterator2(container);
    // }
}
