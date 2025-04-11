#include <iostream>
#include <list>
#include "someClass.h"

int main() {
    someClass cl;
    std::list<int>::iterator iterator;

    cl.add(10);
    cl.add(20);
    cl.add(30);
    cl.add(40);

    std::cout << "Contents of the container: ";
    cl.print();

    std::cout << "Using iterator to print: ";
    for (iterator = cl.begin(); iterator != cl.end(); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;

    cl.remove(30);
    std::cout << "After removing 30: ";
    cl.print();

    std::cout << "Size of the container: " << cl.size() << std::endl;

    cl.clear();
    std::cout << "After clearing, size: " << cl.size() << std::endl;

    return 0;
}
