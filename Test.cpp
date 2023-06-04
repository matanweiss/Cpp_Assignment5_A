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
    }
    SUBCASE("Adding same element multiple times")
    {
        CHECK_NOTHROW(container.addElement(5));
        CHECK_NOTHROW(container.addElement(1));
        CHECK_NOTHROW(container.addElement(1));
        CHECK_NOTHROW(container.addElement(1));
        CHECK_NOTHROW(container.addElement(9));
    }
    SUBCASE("Removing elements")
    {
        CHECK_NOTHROW(container.removeElement(2));
        CHECK_NOTHROW(container.removeElement(2));
        CHECK_NOTHROW(container.removeElement(27));
    }
}