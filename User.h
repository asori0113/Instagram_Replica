#ifndef USER_
#define USER_
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"
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
    User(std::string username, std::string currentPass, std::string email, std::string profilePicturePath);

    void displayProfile();
    void modifyPassword(std::string newPass);
    void displayPosts();
    void displayNthPost(int n);
    void createPost();
    void modifyPost(std::string newTitle, int postNum);
    void editPost(int postIndex);
    void deletePost();
    bool operator==(const User& otherUser) const;

    std::string getUsername();
    std::string getProfilePicture();
    std::string getBio();


};
#include "User.cpp"
#endif