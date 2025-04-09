#ifndef PERSONAL_
#define PERSONAL_

#include "User.h"

class Personal : public User {
private:
    LinkedBag<std::shared_ptr<Post>> privatePosts;

public:
    Personal();
    Personal(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture);

    ~Personal() override;

    Personal(const Personal& other);
    Personal& operator=(const Personal& other);


    std::shared_ptr<User> clone() const override;

    void createPrivatePost(std::string postTitle, std::string url, int duration, bool isReel);

     void displayPosts() override;

     void displayProfile() override;

     void displayNthPost(int n) override;


};


#include "Personal.cpp"
#endif