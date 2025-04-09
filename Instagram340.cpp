
#include <iostream>
#include <string>
#include "Instagram340.h"
/*
Instagram340::Instagram340(const Instagram340& other) {
	int size = other.users.getCurrentSize();
	if (!other.users.isEmpty()) {
	auto user = User(other.users.findKthItem(1)->getItem());
	users.add(user);
	
	for (int i = 2; i < size; i++) {
		auto user = User(other.users.findKthItem(i)->getItem());
		users.append(user);
	}

	}
}

Instagram340& Instagram340::operator=(const Instagram340& other) {
	if (this != &other) {
	

	users.clear();

	if (!other.users.isEmpty()) {

	users.add(User(other.users.findKthItem(1)->getItem()));

	for (int usersNum = 2; usersNum <= other.users.getCurrentSize(); ++usersNum) {
		users.append(User(other.users.findKthItem(usersNum)->getItem()));
	}

	}

	}

	return *this;
}

*/
Instagram340::Instagram340() {

}

Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
				const std::string& bio, const std::string& profilePicture){
	auto newUser = std::make_shared<User>(username, email, password, bio, profilePicture);

	if (users.isEmpty()) {
		users.add(newUser);
	}

	else {
		users.append(newUser);
	}

}

std::shared_ptr<User> Instagram340::getUser(const int& indexK) {


	Node<std::shared_ptr<User> >* userNode = users.findKthItem(indexK);

	if (userNode != NULL) {
		return userNode->getItem();
	}

	return NULL;
}

void Instagram340::displayNthUser(int n) {
	Node<std::shared_ptr<User> >* userNode = users.findKthItem(n);
	if (userNode != NULL) {
		userNode->getItem()->displayUser();
	}

	else {
		std::cout << "User does not exist\n\n";
	}

}

void Instagram340::displayUsers() {
	if (!users.isEmpty()) {

		//Set userNode to headPtr
		Node<std::shared_ptr<User>>* userNode = users.findKthItem(1);

		// Iterate through bag, calling User's display until reach the end
		while (users != NULL) {
			userNode->getItem()->displayUser();
			userNode = userNode->getNext();
		}
	}
	else {
		std::cout << "No user to display\n\n";
	}


}