// TO DO: #include needed standard libraries and your own libraries here
#include "User.h"
#include <string>
// TO DO: function implementations
User() {

}
~User() {
	
}

User(std::string username, std::string currentPass, std::string email, std::string profilePicturePath) {

}

bool operator==(const User& otherUser) const; 

void displayProfile() {

}

void modifyPassword(std::string newPass) {

}

void displayPosts() {

}

void displayNthPost(int n) {

}

void createPost() {

}

void modifyPost(string newTitle, int postNum) {

}

void editPost(int postIndex) {

}

void deletePost() {

}

bool operator==(const User& otherUser) const {

}
// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}
