#ifndef CREATOR_
#define CREATOR_

class Creator   {
private:
public:
    Creator();
    ~Creator();

    Creator(const Creator& other);
    Creator& operator=(const Creator& other);
};


#include "Creator.cpp"
#endif
