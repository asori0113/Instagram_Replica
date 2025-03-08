#ifndef USER_
#define USER_
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"
#include "Reel.h"
#include "Story.h"
class User {
private:
    //LinkedBag contains Post pointers to enable polymorphism.
    LinkedBag<Post*> userPosts;

    std::string username;
    std::string currentPass;
    std::string email;
    std::string profilePicturePath;
    std::string bio;

public:

    User();
    ~User();
    User(std::string name, std::string password, std::string eMail, std::string path);

    void displayProfile();
    void modifyPassword(std::string newPass);
    void displayPosts();
    void displayNthPost(int n);
    void createPost(std::string postTitle, std::string url, int likes, int duration, bool isReel);
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