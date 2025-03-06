// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include "Instagram340.h"
#include "User.h"

Instagram340::Instagram340(){
	// TO DO: implement constructor
}

Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
				const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function

	User newUser;
	

	newUser.append(username);
	newUser.append(email);
	newUser.append(password);
	newUser.append(bio);
	newUser.append(profilePicture);
	
	users.append(newUser);
	


}

User Instagram340::getUser(const int& indexK){
	Node<User>* userNode = users.findKthItem(indexK);

	if (userNode != NULL) {
		return userNode->getItem();
	}

	return NULL;

}