#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>

using namespace ariel;

TEST_CASE("Test 1-Initialization of MagicalContainer")
{
    MagicalContainer container;
    CHECK(container.size() == 0);
}

TEST_CASE("Test 2-Check Trowing Exception")
{
    MagicalContainer container;
    CHECK_THROWS_AS(container.removeElement(1), std::runtime_error);
}

TEST_CASE("Test 3-Add elements to MagicalContainer")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK(container.size() == 3);
}

TEST_CASE("Test 4-Check Trowing Exception removeElement that not exist")
{
    MagicalContainer container;
    container.addElement(2);
    CHECK_THROWS(container.removeElement(1));
}

TEST_CASE("Test 5-Remove elements from MagicalContainer")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.removeElement(1);
    CHECK(container.size() == 2);
    CHECK_THROWS(container.removeElement(1));
}

TEST_CASE("Test 6-Check AscendingIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    auto it = ascIter.begin();

    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 5);
}


TEST_CASE("Test 7-Check AscendingIterator update")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    container.addElement(6);
    container.removeElement(1);
    auto it = ascIter.begin();
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 6);

}

TEST_CASE("Test 8-Check end point AscendingIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    auto it = ascIter.begin();
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    CHECK(it == ascIter.end());

}

TEST_CASE("Test 9-Check Copy constructor AscendingIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(ascIter);
    auto it = ascIter.begin();
    auto it2 = ascIter2.begin();
    CHECK(*it == *it2);
    ++it;
    ++it2;
    CHECK(*it == *it2);
    ++it;
    CHECK(*it != *it2);
    ++it2;
    CHECK(*it == *it2);
    ++it;
    ++it2;
    CHECK(*it == *it2);
    ++it;
    ++it2;
    CHECK(*it == *it2);

    
}

TEST_CASE("Test 10-Check Copy constructor AscendingIterator update")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(ascIter);
    container.addElement(6);
    container.removeElement(1);
    auto it = ascIter2.begin();
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 6);

}

TEST_CASE("Test 11-Check Equality comparison AscendingIterator and  Inequality comparison ")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(container);
    CHECK(ascIter == ascIter2);
    ++ascIter;
    CHECK(ascIter != ascIter2);
    ++ascIter2;
    CHECK(ascIter == ascIter2);
}

TEST_CASE("Test 12-Check SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::SideCrossIterator crossIter(container);
    auto it = crossIter.begin();
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 3);

}

TEST_CASE("Test 13-Check SideCrossIterator update")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::SideCrossIterator crossIter(container);
    container.addElement(6);
    container.removeElement(1);
    auto it = crossIter.begin();
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 6);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 4);
   
}

TEST_CASE("Test 14-check endpoint SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::SideCrossIterator crossIter(container);
     auto it = crossIter.begin();
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    CHECK(it == crossIter.end());
    CHECK_THROWS(++it);
}

TEST_CASE("Test 15-Check Copy constructor SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer::SideCrossIterator crossIter2(crossIter);
    auto it = crossIter.begin();
    auto it2 = crossIter2.begin();
    CHECK(*it == *it2);
    ++it;
    ++it2;
    CHECK(*it == *it2);
    ++it;
    CHECK(*it != *it2);
    ++it2;
    CHECK(*it == *it2);
    ++it;
    ++it2;
    CHECK(*it == *it2);
    ++it;
    ++it2;
    CHECK(*it == *it2);

}

TEST_CASE("Test 16-Check Equality comparison SideCrossIterator and  Inequality comparison ")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer::SideCrossIterator crossIter2(container);
    CHECK(crossIter == crossIter2);
    ++crossIter;
    CHECK(crossIter != crossIter2);
    ++crossIter2;
    CHECK(crossIter == crossIter2);
}

TEST_CASE("Test 17-Check PrimeIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);
    CHECK(*primeIter.begin() == 2);
    ++primeIter;
    CHECK(*primeIter.begin() == 3);
    ++primeIter;
    CHECK(*primeIter.begin() == 5);
}

TEST_CASE("Test 18-Check PrimeIterator update")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);
    container.addElement(7);
    container.removeElement(2);
    MagicalContainer::PrimeIterator primeIter(container);
    auto it = primeIter.begin();
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 7);
    
}

TEST_CASE("Test 19-Check endpoint PrimeIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);
    ++primeIter;
    ++primeIter;
    ++primeIter;
    CHECK(primeIter.begin() == primeIter.end());
    CHECK_THROWS(++primeIter);
}

TEST_CASE("Test 20-Check Copy constructor PrimeIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::PrimeIterator primeIter2(primeIter);
    CHECK(*primeIter2.begin() == 2);
    ++primeIter2;
    CHECK(*primeIter2.begin() == 3);
    ++primeIter2;
    CHECK(*primeIter2.begin() == 5);
}

TEST_CASE("Test 21-Check Equality comparison PrimeIterator and  Inequality comparison ")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::PrimeIterator primeIter2(container);
    CHECK(primeIter == primeIter2);
    ++primeIter;
    CHECK(primeIter != primeIter2);
    ++primeIter2;
    CHECK(primeIter == primeIter2);
}




