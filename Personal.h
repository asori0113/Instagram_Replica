#ifndef PERSONAL_
#define PERSONAL_

#include "User.h"

class Personal : public User  {
private:
public:
    Personal();
    ~Personal() override;

    Personal(const Personal& other);
    Personal& operator=(const Personal& other);

    
    std::shared_ptr<User> clone() const override; 
};


#include "Personal.cpp"
#endif
