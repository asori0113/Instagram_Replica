
#include <iostream>
#include <string>
#include "Instagram340.h"
#include <memory>



Instagram340::Instagram340() {

}

Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

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

void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
				const std::string& bio, const std::string& profilePicture){
	User newUser = User(username, email, password, bio, profilePicture);

	if (users.isEmpty()) {
		users.add(newUser);
	}

	else {
		users.append(newUser);
	}

}

User Instagram340::getUser(const int& indexK){
	Node<User>* userNode = users.findKthItem(indexK);

	if (userNode != NULL) {
		
		return (userNode->getItem());
	}
	
	return User();

}