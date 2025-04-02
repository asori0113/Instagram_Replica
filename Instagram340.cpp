// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include <memory>
#include "Instagram340.h"


Instagram340::Instagram340() { // After discussing, we found that there is nothing we can put in the default constructor (right?????). There is nothing to initialize.

}

Instagram340::Instagram340(const Instagram340& other) {
	int size = other.users.getCurrentSize();

	auto user = std::make_shared<User>(other.users.findKthItem(1)->getItem().get());
	users.add(std::move(user));

	for (int i = 0; i < size; i++) {
		auto user = std::make_shared<User>(other.users.findKthItem(i)->getItem().get());
		users.append(std::move(user));
	}
}

Instagram340& Instagram340::operator=(const Instagram340& other) {
	if (this == &other) {
		return *this;
	}

	users.clear();

	users.add(other.users.findKthItem(1)->getItem().get()->clone());

	for (int usersNum = 2; usersNum <= other.users.getCurrentSize(); ++usersNum) {
		users.append(other.users.findKthItem(usersNum)->getItem().get()->clone());
	}

	return *this;
}



Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
				const std::string& bio, const std::string& profilePicture){
	std::shared_ptr<User> newUser = std::make_shared<User>(username, email, password, bio, profilePicture);

	if (users.isEmpty()) {
		users.add(newUser);
	}

	else {
		users.append(newUser);
	}

}

User Instagram340::getUser(const int& indexK){
	Node<std::shared_ptr<User>>* userNode = users.findKthItem(indexK);

	if (userNode != NULL) {
		return *userNode->getItem();
	}
	
	return User();
}
