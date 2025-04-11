#ifndef SOMECLASS_
#define SOMECLASS_

#include <list>

class someClass {
private:
    std::list<int> container; 

public:
    void add(int value);

    void remove(int value);

    void print() const;
    
    size_t size() const;

    void clear();

    std::list<int>::iterator begin();

    std::list<int>::iterator end();

};

#include "someClass.cpp"
#endif