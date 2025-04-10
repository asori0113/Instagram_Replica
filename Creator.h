
#ifndef CREATOR_
#define CREATOR_

#include "User.h"

class Creator : public User  {
private:
    bool isVerified;
public:
    Creator();
    Creator(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture);
    ~Creator() override;

    Creator(const Creator& other);
    Creator& operator=(const Creator& other);

    std::shared_ptr<User> clone() const override;

    void makeVerified(bool status);
    bool checkVerification();
    void displayProfile() override;



};


#include "Creator.cpp"
#endif

