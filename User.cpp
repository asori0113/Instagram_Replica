#include "User.h"
#include <string>
#include <iostream>
#include <memory>

User::User() : username(""), currentPass(""), email(""), profilePicturePath(""), postCount(0) {

}

User::~User() {
	User::userPosts.clear();
}

User::User(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture) : username(name), email(emailAdd), currentPass(password), bio(bioStr), profilePicturePath(profilePicture), postCount(0) {

}

User::User(const User& otherUser) : username(otherUser.getUsername()), email(otherUser.getEmail()), currentPass(otherUser.getPass()), bio(otherUser.getBio()), profilePicturePath(otherUser.getProfilePicture()) {
	/*
	The suggestion of a clone() function comes from a prompt to chatGPT about copy constructors and polymorphism.

	We encounter a particular problem when copying a polymorphic object: data slicing. When we dereference a derived object and store its information in a base class container we lose the data from derived class.
	
	clone() solves this by dynamically allocating memory for a copy of the object that called the aforementioned method and returning a pointer to it. 

	*/

	if (!otherUser.userPosts.isEmpty()) {
		//No need for make_shared since clone() takes care of it.
		userPosts.add(otherUser.userPosts.findKthItem(1)->getItem().get()->clone());

		for (int postNum = 2; postNum <= postCount; ++postNum) {
			userPosts.append(otherUser.userPosts.findKthItem(postNum)->getItem().get()->clone());
		}

		postCount = otherUser.userPosts.getCurrentSize();


	}
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
		Node<std::shared_ptr<Post>>* postNode = userPosts.findKthItem(1);

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
	Node<std::shared_ptr<Post>>* post = userPosts.findKthItem(n);

	if (post != NULL) {
		post->getItem()->display();
	}

	else {
		std::cout << "No post to display\n\n";
	}
	
}

void User::createPost(const std::string& postTitle, const std::string& url, int duration, bool isReel) {
	
	std::shared_ptr<Post> newPost;

	//Check whether reel or story
	if (isReel) {
		newPost = std::make_shared<Reel>(postTitle, url, duration);
	}
	else {
		newPost = std::make_shared<Story>(postTitle, url, duration);
	}


	//Add to usersPost if empty, append otherwise.
	if (userPosts.isEmpty()) {
		userPosts.add((newPost));
		postCount++;
	}

	else {
		userPosts.append((newPost));
		postCount++;
	}

	newPost = NULL;
}

void User::modifyNthPost(int n) {
	userPosts.findKthItem(n)->getItem().get()->editPost();

}

void User::editNthPost(const std::string& newTitle, int n) {
	userPosts.findKthItem(n)->getItem().get()->editTitle(newTitle);
}


void User::deletePost(int n) {
	userPosts.remove(userPosts.findKthItem(n)->getItem());
	postCount--;
	
}
std::string User::getEmail() const {
	return email;
}

std::string User::getUsername() const {
	return username;
}

std::string User::getBio() const {
	return bio;
}

std::string User::getProfilePicture() const {
	return profilePicturePath;
}

std::string User::getPass() const {
	return currentPass;
}
int User::getPostCount() const {
	return postCount;
}



// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}