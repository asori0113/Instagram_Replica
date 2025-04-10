#ifndef CREATOR_
#define CREATOR_

#include "User.h"

class Creator : public User  {
private:
    bool isVerified;
public:
    Creator();
    ~Creator() override;

    Creator(const Creator& other);
    Creator& operator=(const Creator& other);

    virtual std::shared_ptr<User> clone() const override;

    void displayProfile() override;

    void makeVerified() {
        char ans;
        while (ans != 'n' || ans != 'y') {
            if (isVerified == false) {
                std::cout << "\nWould you like to verify (y/n): ";
                std::cin >> ans;
                if (ans == 'y') {
                    isVerified = true;
                }
                else if (ans == 'n') {
                    isVerified = false;
                }
                else {
                    std::cout << "Invalid Response\n";
                }        

            }

        }
    }

    
};


#include "Creator.cpp"
#endif

