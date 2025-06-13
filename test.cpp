#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include "Iterators.hpp"

using namespace contain;

TEST_CASE("MyContainer basic operations") {
    SUBCASE("Empty container") {
        MyContainer<int> container;
        CHECK(container.size() == 0);
    }

    SUBCASE("Container with initial array") {
        int arr[] = {1, 2, 3, 4, 5};
        MyContainer<int> container(arr, 5);
        CHECK(container.size() == 5);
    }

    SUBCASE("Add and remove operations") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        container.add(2);
        container.add(3);
        CHECK(container.size() == 4);
        
        container.remove(2);
        CHECK(container.size() == 2);
    }
}

TEST_CASE("Iterator tests") {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    MyContainer<int> container(arr, 8);

    SUBCASE("AscendingOrder iterator") {
        AscendingOrder<int> iter(container);
        CHECK(iter.hasNext() == true);
        CHECK(iter.next() == 1);
        CHECK(iter.next() == 1);
        CHECK(iter.next() == 2);
    }

    SUBCASE("DescendingOrder iterator") {
        DescendingOrder<int> iter(container);
        CHECK(iter.hasNext() == true);
        CHECK(iter.next() == 9);
        CHECK(iter.next() == 6);
        CHECK(iter.next() == 5);
    }

    SUBCASE("Order iterator (original order)") {
        Order<int> iter(container);
        CHECK(iter.hasNext() == true);
        CHECK(iter.next() == 3);
        CHECK(iter.next() == 1);
        CHECK(iter.next() == 4);
    }

    SUBCASE("ReverseOrder iterator") {
        ReverseOrder<int> iter(container);
        CHECK(iter.hasNext() == true);
        CHECK(iter.next() == 6);
        CHECK(iter.next() == 2);
        CHECK(iter.next() == 9);
    }
}

TEST_CASE("Iterator reset functionality") {
    int arr[] = {1, 2, 3, 4, 5};
    MyContainer<int> container(arr, 5);

    SUBCASE("AscendingOrder reset") {
        AscendingOrder<int> iter(container);
        iter.next();
        iter.next();
        iter.reset();
        CHECK(iter.next() == 1);
    }

    SUBCASE("DescendingOrder reset") {
        DescendingOrder<int> iter(container);
        iter.next();
        iter.next();
        iter.reset();
        CHECK(iter.next() == 5);
    }
}

TEST_CASE("Copy constructor tests") {
    int arr[] = {1, 2, 3, 4, 5};
    MyContainer<int> container(arr, 5);

    SUBCASE("AscendingOrder copy") {
        AscendingOrder<int> iter1(container);
        iter1.next(); // advance original iterator
        AscendingOrder<int> iter2(iter1);
        CHECK(iter2.next() == 2);
    }

    SUBCASE("DescendingOrder copy") {
        DescendingOrder<int> iter1(container);
        iter1.next(); // advance original iterator
        DescendingOrder<int> iter2(iter1);
        CHECK(iter2.next() == 4);
    }
}