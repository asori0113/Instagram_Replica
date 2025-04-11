#include <iostream>
#include <list>

class someClass {
private:
    std::list<int> container;  // list to store integers

public:
    //  add an element
    void add(int value) {
        container.push_back(value);  // Add value at the end
    }

    // remove an element 
    void remove(int value) {
        container.remove(value);  // Remove all value
    }

    // print all 
    void print() {
        std::cout << "Container list elements: ";
        for (const auto& val : container) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // size of the container
    size_t size() {
        return container.size();
    }

    //  clear 
    void clear() {
        container.clear();
    }
};

int main() {
    someClass cl;

    // Adding elements to the list
    cl.add(10);
    cl.add(20);
    cl.add(30);
    cl.add(40);

    // Printing the container's elements
    cl.print();

    // Removing an element
    cl.remove(30);
    std::cout << "After removing 30: ";
    cl.print();

    // Size of the list
    std::cout << "Size of the container: " << cl.size() << std::endl;

    // Clearing the container
    cl.clear();
    std::cout << "After clearing, size: " << cl.size() << std::endl;

    return 0;
}