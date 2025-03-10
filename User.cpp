#include "User.h"
#include <string>
#include <iostream>

// TO DO: function implementations
User::User() : username(""), currentPass(""), email(""), profilePicturePath(""), postCount(0) {

}
User::~User() {

	
}

User::User(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture) : username(name), email(emailAdd), currentPass(password), bio(bioStr), profilePicturePath(profilePicture), postCount(0) {

}

int User::getPostCount() {
	return postCount;
}

void User::displayProfile() {
	std::cout << "===========================\n\n";
	std::cout << getUsername() << "'s" << " Profile\n";
	std::cout << getBio() << "\n\n";

	//Profile picture should also be displayed but since we're not using GUI, we're skipping it. 
	

}

void User::modifyPassword(const std::string& newPass) {
	currentPass = newPass;
}

void User::displayPosts() {
	if (!userPosts.isEmpty()) {

		//Set postNode to headPtr
		Node<Post*>* postNode = userPosts.findKthItem(1);

		// Iterate through bag, calling Post's display until reach the end
		while (postNode != NULL) {
			postNode->getItem()->display();
			postNode = postNode->getNext();
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

void User::createPost(const std::string& postTitle, const std::string& url, int duration, bool isReel) {
	Post* newPost = nullptr;

	//Check whether reel or story
	if (isReel) {
		newPost = new Reel(postTitle, url, duration);
	}
	else {
		newPost = new Story(postTitle, url, duration);
	}


	//Add to usersPost if empty, append otherwise.
	if (userPosts.isEmpty()) {
		userPosts.add(newPost);
		postCount++;
	}

	else {
		userPosts.append(newPost);
		postCount++;
	}
}

void User::modifyNthPost(const std::string& newTitle, int n) {
	Node<Post*>* post = userPosts.findKthItem(n);
	post->getItem()->editTitle(newTitle);
	post->getItem()->editPost();

}


void User::deletePost(int n) {
	userPosts.findKthItem(n)->setItem(nullptr);
	userPosts.remove(userPosts.findKthItem(n)->getItem());
	postCount--;
	
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