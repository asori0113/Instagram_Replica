#include <iostream>
#include <list>
#include "someClass.h"


void someClass::add(int value) {
    container.push_back(value);  // Add value at the end
}

// remove an element 
void someClass::remove(int value) {
    container.remove(value);  // Remove all value
}

// print all 
void someClass::print() const {
    std::cout << "Container list elements: ";
    for (const auto& value : container) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}


// size of the container
size_t someClass::size() const{
    return container.size();
}

//  clear 
void someClass::clear() {
    container.clear();
}

// iterators
std::list<int>::iterator someClass::begin() {
    return container.begin();
}

std::list<int>::iterator someClass::end() {
    return container.end();
}