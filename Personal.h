#ifndef PERSONAL_
#define PERSONAL_

#include "User.h"

class Personal : public User {
private:

public:
    Personal();
    Personal(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture);

    ~Personal() override;

    Personal(const Personal& other);
    Personal& operator=(const Personal& other);

    std::shared_ptr<User> clone() const override;

     void displayProfile() override;


};


#include "Personal.cpp"
#endif