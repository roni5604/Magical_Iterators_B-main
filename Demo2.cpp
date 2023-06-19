#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;

int main() {
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(23);
    container.addElement(4);
    container.addElement(37);
    container.addElement(15);
    container.addElement(5);

    // Remove an element from the container and display the size
    container.removeElement(5);
    std::cout << "Expected size of container after removing an element: 4" << std::endl;
    std::cout << "Actual size: " << container.size() << std::endl;

    // Add an element to the container and display the size
    container.addElement(7);
    std::cout << "Expected size of container after adding an element: 5" << std::endl;
    std::cout << "Actual size: " << container.size() << std::endl;

    // Print container size
    std::cout << "Expected size of container: 5" << std::endl;
    std::cout << "Actual size: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Expected elements in ascending order: 4 7 15 23 37" << std::endl;
    std::cout << "Actual elements: ";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';  
    }
    std::cout << std::endl;

    // Use SideCrossIterator to display elements in cross order
    std::cout << "Expected elements in cross order: 4 37 7 23 15" << std::endl;
    std::cout << "Actual elements: ";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  
    }
    std::cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    std::cout << "Expected prime numbers: 7 23 37" << std::endl;
    std::cout << "Actual prime numbers: ";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  
    }
    std::cout << std::endl;

    return 0;
}
