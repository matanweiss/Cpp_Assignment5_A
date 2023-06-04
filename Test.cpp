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

    SUBCASE("GT and LT operators")
    {
        MagicalContainer::AscendingIterator ascendingIterator1(container);
        MagicalContainer::AscendingIterator ascendingIterator2(container);
        ++ascendingIterator2;
        ++ascendingIterator2;
        CHECK(ascendingIterator1 < ascendingIterator2);
        CHECK_FALSE(ascendingIterator1 > ascendingIterator2);
        ++ascendingIterator1;
        CHECK(ascendingIterator1 < ascendingIterator2);
        ++ascendingIterator1;
        CHECK_FALSE(ascendingIterator1 < ascendingIterator2);
        CHECK(ascendingIterator1 == ascendingIterator2);
        ++ascendingIterator1;
        CHECK(ascendingIterator1 != ascendingIterator2);
    }
}

TEST_CASE("PrimeIterator")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(7));
    CHECK_NOTHROW(container.addElement(1));
    CHECK_NOTHROW(container.addElement(11));
    CHECK_NOTHROW(container.addElement(19));
    CHECK_NOTHROW(container.addElement(101));
    CHECK_NOTHROW(container.addElement(3));

    SUBCASE("order of iterator")
    {
        MagicalContainer::PrimeIterator PrimeIterator(container);
        CHECK(*PrimeIterator == 1);
        ++PrimeIterator;
        CHECK(*PrimeIterator == 3);
        ++PrimeIterator;
        CHECK(*PrimeIterator == 7);
        ++PrimeIterator;
        CHECK(*PrimeIterator == 11);
        ++PrimeIterator;
        CHECK(*PrimeIterator == 19);
        ++PrimeIterator;
        CHECK(*PrimeIterator == 101);
        ++PrimeIterator;
        CHECK_THROWS(*PrimeIterator);
    }

    SUBCASE("GT and LT operators")
    {
        MagicalContainer::PrimeIterator PrimeIterator1(container);
        MagicalContainer::PrimeIterator PrimeIterator2(container);
        ++PrimeIterator2;
        ++PrimeIterator2;
        CHECK(PrimeIterator1 < PrimeIterator2);
        CHECK_FALSE(PrimeIterator1 > PrimeIterator2);
        ++PrimeIterator1;
        CHECK(PrimeIterator1 < PrimeIterator2);
        ++PrimeIterator1;
        CHECK_FALSE(PrimeIterator1 < PrimeIterator2);
        CHECK(PrimeIterator1 == PrimeIterator2);
        ++PrimeIterator1;
        CHECK(PrimeIterator1 != PrimeIterator2);
    }
}

TEST_CASE("SideCrossIterator")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(7));
    CHECK_NOTHROW(container.addElement(1));
    CHECK_NOTHROW(container.addElement(11));
    CHECK_NOTHROW(container.addElement(19));
    CHECK_NOTHROW(container.addElement(101));
    CHECK_NOTHROW(container.addElement(3));

    SUBCASE("order of iterator")
    {
        MagicalContainer::SideCrossIterator SideCrossIterator(container);
        CHECK(*SideCrossIterator == 1);
        ++SideCrossIterator;
        CHECK(*SideCrossIterator == 101);
        ++SideCrossIterator;
        CHECK(*SideCrossIterator == 3);
        ++SideCrossIterator;
        CHECK(*SideCrossIterator == 19);
        ++SideCrossIterator;
        CHECK(*SideCrossIterator == 7);
        ++SideCrossIterator;
        CHECK(*SideCrossIterator == 11);
        ++SideCrossIterator;
        CHECK_THROWS(*SideCrossIterator);
    }

    SUBCASE("GT and LT operators")
    {
        MagicalContainer::SideCrossIterator SideCrossIterator1(container);
        MagicalContainer::SideCrossIterator SideCrossIterator2(container);
        ++SideCrossIterator2;
        ++SideCrossIterator2;
        CHECK(SideCrossIterator1 < SideCrossIterator2);
        CHECK_FALSE(SideCrossIterator1 > SideCrossIterator2);
        ++SideCrossIterator1;
        CHECK(SideCrossIterator1 < SideCrossIterator2);
        ++SideCrossIterator1;
        CHECK_FALSE(SideCrossIterator1 < SideCrossIterator2);
        CHECK(SideCrossIterator1 == SideCrossIterator2);
        ++SideCrossIterator1;
        CHECK(SideCrossIterator1 != SideCrossIterator2);
    }
}

TEST_CASE("Different iterator types")
{
    MagicalContainer container;
    container.addElement(12);
    container.addElement(2);
    container.addElement(18);
    container.addElement(29);

    MagicalContainer::AscendingIterator ascendingIterator(container);
    MagicalContainer::SideCrossIterator crossIterator(container);
    MagicalContainer::PrimeIterator primeIterator(container);
    bool temp;

    SUBCASE("equality operator")
    {
        CHECK_THROWS(temp = (ascendingIterator == crossIterator));
        CHECK_THROWS(temp = (ascendingIterator == primeIterator));
        CHECK_THROWS(temp = (primeIterator == crossIterator));
    }

    SUBCASE("inequality operator")
    {
        CHECK_THROWS(temp = (ascendingIterator != crossIterator));
        CHECK_THROWS(temp = (ascendingIterator != primeIterator));
        CHECK_THROWS(temp = (primeIterator != crossIterator));
    }
}

TEST_CASE("Iterators with different containers")
{
    MagicalContainer container1;
    MagicalContainer container2;
    CHECK_NOTHROW(container1.addElement(10));
    CHECK_NOTHROW(container1.addElement(1));
    CHECK_NOTHROW(container1.addElement(2));
    CHECK_NOTHROW(container2.addElement(20));
    CHECK_NOTHROW(container2.addElement(30));
    CHECK_NOTHROW(container2.addElement(10));

    MagicalContainer::SideCrossIterator crossIterator1(container1);
    MagicalContainer::SideCrossIterator crossIterator2(container2);
    MagicalContainer::AscendingIterator ascendingIterator1(container1);
    MagicalContainer::PrimeIterator primeIterator2(container2);

    bool temp;

    CHECK_THROWS(temp = (crossIterator1 == crossIterator2));
    CHECK_THROWS(temp = (crossIterator1 == primeIterator2));
    CHECK_THROWS(temp = (ascendingIterator1 == primeIterator2));
}
