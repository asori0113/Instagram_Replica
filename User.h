// TO DO: #include all the standard libraries and your own libraries here
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"
// To DO: define the class User with the necessary functions and data fields
#ifndef USER_
#define USER_

class User {
private:
    LinkedBag<Post> userPosts;
    std::string username;
    std::string currentPass;
    std::string email;
    std::string profilePicturePath;
    std::string bio;

public:
    User();
    ~User();
    User(std::string username, std::string currentPass, std::string email, std::string profilePicturePath) {}

    void displayProfile();
    void modifyPassword(std::string newPass);
    void displayPosts();
    void displayNthPost(int n);
    void createPost();
    void modifyPost(std::string newTitle, int postNum);
    void editPost(int postIndex);
    void deletePost();
    bool operator==(const User& otherUser) const;


    
    
};




// This is a function that allows you to compare two users based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype: 

#include "User.cpp"
#endif
