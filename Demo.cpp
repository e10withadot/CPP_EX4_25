#include <iostream>
#include "MyContainer.hpp"
using namespace ariel;
int main() {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    std::cout << "Size of container: " << container.size() << std::endl;

    MyContainer<int>::AscendingOrder ascIter(container);
    for (auto it = ascIter.begin_ascending_order(); it != ascIter.end_ascending_order(); ++it) {
        std::cout << *it << ' ';   // 1 2 6 7 15
    }
    std::cout << std::endl;

    MyContainer<int>::DescendingOrder descIter(container);
    for (auto it = descIter.begin_descending_order(); it != descIter.end_descending_order(); ++it) {
        std::cout << *it << ' ';  // 15 7 6 2 1
    }
    std::cout << std::endl;

    MyContainer<int>::SideCrossOrder sidecrossIter(container);
    for (auto it = sidecrossIter.begin_side_cross_order(); it != sidecrossIter.end_side_cross_order(); ++it) {
        std::cout << *it << ' ';  // 1 15 2 7 6
    }
    std::cout << std::endl;

    MyContainer<int>::ReverseOrder revIter(container);
    for (auto it = revIter.begin_reverse_order(); it != revIter.end_reverse_order(); ++it) {
        std::cout << *it << ' ';  // 2 1 6 15 7
    }
    std::cout << std::endl;

    MyContainer<int>::Order orderIter(container);
    for (auto it = orderIter.begin_order(); it != orderIter.end_order(); ++it) {
        std::cout << *it << ' ';  // 7 15 6 1 2
    }
    std::cout << std::endl;

    MyContainer<int>::MiddleOutOrder midoutIter(container);
    for (auto it = midoutIter.begin_middle_out_order(); it != midoutIter.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';  // 6 15 1 7 2
    }
    std::cout << std::endl;

  

    return 0;
}
