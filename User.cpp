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
	int postNumber = 1;

	if (!userPosts.isEmpty()) {

		// Continue to display until you reach the end
		while (postNumber != userPosts.getCurrentSize()) {
			displayNthPost(postNumber);
			postNumber++;
		}
	}
	else {
		std::cout << "No post to display\n\n";
	}


}

void User::displayNthPost(int n) {
	Node<Post*>* post = userPosts.findKthItem(n);

	if (post != NULL) {
		post->getItem()->display();
	}

	else {
		std::cout << "No post to display\n\n";
	}
	
}

void User::createPost(std::string postTitle, std::string url, int likes, int duration, bool isReel) {
	

	Post* newPost = nullptr;

	//Check whether reel or story
	if (isReel) {
		newPost = new Reel(postTitle, url, likes, duration);
	}
	else {
		newPost = new Story(postTitle, url, likes, duration);
	}


	//Add to usersPost if empty, append otherwise.
	if (userPosts.isEmpty()) {
		userPosts.add(newPost);
	}

	else {
		userPosts.append(newPost);
	}

	
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