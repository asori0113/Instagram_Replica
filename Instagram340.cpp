#include "Instagram340.h"
#include <iostream>
#include <string>
#include <memory>


Instagram340::Instagram340() {

}

Instagram340::~Instagram340() {
	Instagram340::users.clear();
}

Instagram340::Instagram340(const Instagram340& other) {
	int size = other.users.getCurrentSize();
	if (!other.users.isEmpty()) {
		auto user = other.users.findKthItem(1)->getItem().get()->clone();
		users.add(user);

		for (int i = 2; i < size; i++) {
			auto user = other.users.findKthItem(i)->getItem().get()->clone();
			users.append(user);
		}

	}
}

Instagram340& Instagram340::operator=(const Instagram340& other) {
	if (this != &other) {


		users.clear();

		if (!other.users.isEmpty()) {

			users.add(other.users.findKthItem(1)->getItem().get()->clone());

			for (int usersNum = 2; usersNum <= other.users.getCurrentSize(); ++usersNum) {
				users.append(other.users.findKthItem(usersNum)->getItem());
			}

		}

	}

	return *this;
}

void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture, const bool isCreator, const bool verified) {

	std::shared_ptr<User> newUser;

	//Check whether reel or story
	if (isCreator) {
		newUser = std::make_shared<Creator>(username,email,password,bio,profilePicture, verified);
	}
	else {
		newUser = std::make_shared<Personal>(username, email, password, bio, profilePicture);
	}


	//Add to usersPost if empty, append otherwise.
	if (users.isEmpty()) {
		users.add((newUser));
	}

	else {
		users.append((newUser));
	}

	newUser = NULL;
}


void Instagram340::displayUsers() {
	if (!users.isEmpty()) {

		Node<std::shared_ptr<User>>* userNode = users.findKthItem(1);

		while (userNode != NULL) {
			userNode->getItem()->displayProfile();
			userNode = userNode->getNext();
		}
	}
	else {
		std::cout << "No user to display\n\n";
	}


}

void Instagram340::displayNthUser(const int& n) {
	Node<std::shared_ptr<User>>* user = users.findKthItem(n);

	if (user != NULL) {
		user->getItem()->displayProfile();
	}

	else {
		std::cout << "No user to display\n\n";
	}

}

std::shared_ptr<User> Instagram340::getUser(const int& indexK) {
	Node<std::shared_ptr<User> >* userNode = users.findKthItem(indexK);

	if (userNode != NULL) {

		return userNode->getItem();
	}

	return nullptr;

}

