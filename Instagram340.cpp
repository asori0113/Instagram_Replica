
#include <iostream>
#include <string>
#include "Instagram340.h"
#include <memory>

 
Instagram340::Instagram340() {

}

Instagram340::~Instagram340(){
	Instagram340::users.clear();
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

