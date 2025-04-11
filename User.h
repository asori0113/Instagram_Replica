#ifndef USER_
#define USER_
#include "LinkedBagDS/LinkedBag.h"
#include "Post.h"
#include "Reel.h"
#include "Story.h"
class User {
protected:
    LinkedBag<std::shared_ptr<Post>> userPosts;
    std::string getPass() const;
    std::string getEmail() const;

private:
    //LinkedBag contains Post pointers to enable polymorphism.
   

    std::string username;
    std::string currentPass;
    std::string email;
    std::string profilePicturePath;
    std::string bio;
    int postCount;

public:
    User& operator=(const User& other);
    User();
    virtual ~User();
    User(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture);
    User(const User& otherUser);

    
    void modifyPassword(const std::string& newPass);
    
    void createPost(const std::string& postTitle, const std::string& url, int duration, bool isReel);
    void modifyNthPost(int n);
    void editNthPost(const std::string& newTitle, int n);
    void deletePost(int n);

    virtual void displayProfile();
    void displayPosts();
    void displayNthPost(int n);
    virtual std::shared_ptr<User> clone() const;

    bool operator==(const User& otherUser) const;
    int getPostCount() const;
    std::string getUsername() const;
    std::string getProfilePicture() const;
    std::string getBio() const;

    



};
#include "User.cpp"
#endif