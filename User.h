#ifndef USER_
#define USER_
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"
#include "Reel.h"
#include "Story.h"
class User {
private:
    //LinkedBag contains Post pointers to enable polymorphism.
    LinkedBag<std::shared_ptr<Post> > userPosts;

    std::string username;
    std::string currentPass;
    std::string email;
    std::string profilePicturePath;
    std::string bio;
    int postCount;

    std::string getPass() const;
    std::string getEmail() const;

public:

    User();
    ~User();
    User(const User& other);
    User(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture);
    User& operator=(const User& other);
   

    void displayProfile();
    void modifyPassword(const std::string& newPass);
    void displayPosts();
    void displayNthPost(int n);
    void createPost(const std::string& postTitle, const std::string& url, int duration, bool isReel);
    void modifyNthPost(int n);
    void editNthPost(const std::string& newTitle, int n);
    void deletePost(int n);

    int getPostCount();
    bool operator==(const User& otherUser) const;

    std::string getUsername();
    std::string getProfilePicture();
    std::string getBio();


};
#include "User.cpp"
#endif