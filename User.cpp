#include "User.h"
#include <string>
#include <iostream>

// TO DO: function implementations
User::User() : username(""), currentPass(""), email(""), profilePicturePath("") {

}
User::~User() {

}

User::User(std::string name, std::string password, std::string eMail, std::string path): username(name), currentPass(password), email(eMail), profilePicturePath(path) {

}

void User::displayProfile() {
	std::cout << "===========================\n\n";
	std::cout << getUsername() << "'s" << " Profile\n";
	std::cout << getBio() << "\n\n";

	//Profile picture should also be displayed but since we're not using GUI, we're skipping it. 
	

}

void User::modifyPassword(std::string newPass) {
	currentPass = newPass;
}

void User::displayPosts() {
	
}

void User::displayNthPost(int n) {

}

void User::createPost() {

}

void User::modifyPost(std::string newTitle, int postNum) {

}

void User::editPost(int postIndex) {

}

void User::deletePost() {

}

std::string User::getUsername() {
	return username;
}

std::string User::getBio() {
	return bio;
}

std::string User::getProfilePicture() {
	return profilePicturePath;
}



// This is a function that allows you to compare two users based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype: 

// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}