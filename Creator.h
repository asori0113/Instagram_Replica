/*
#ifndef CREATOR_
#define CREATOR_

#include "User.h"

class Creator : public User  {
private:
public:
    Creator();
    ~Creator() override;

    Creator(const Creator& other);
    Creator& operator=(const Creator& other);

    virtual std::shared_ptr<User> clone() const override;

    
};


#include "Creator.cpp"
#endif

*/
