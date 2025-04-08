#ifndef PERSONAL_
#define PERSONAL_

class Personal   {
private:
public:
    Personal();
    ~Personal();

    Personal(const Personal& other);
    Personal& operator=(const Personal& other);
};


#include "Personal.cpp"
#endif
