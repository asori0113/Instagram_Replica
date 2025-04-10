#ifndef PERSONAL_
#define PERSONAL_

#include "User.h"

class Personal : public User  {
private:
    int draftCount;
public:
    Personal();
    ~Personal() override;
    Personal(int Count);

    Personal(const Personal& other);
    Personal& operator=(const Personal& other);

    
    std::shared_ptr<User> clone() const override; 

    void displayProfile() override;
    void createDraft();

    int getDraftCount();

};


#include "Personal.cpp"
#endif
