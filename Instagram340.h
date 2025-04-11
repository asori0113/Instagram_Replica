// TO DO include necessary libraries

#ifndef INSTAGRAM340
#define INSTAGRAM340
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"
#include "Personal.h"
#include "Creator.h"
#include <memory>
// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list
class Instagram340 {
	private:
		LinkedBag<std::shared_ptr<User>> users;

	public:
		Instagram340();
		~Instagram340();
		Instagram340(const Instagram340& other);
		Instagram340& operator=(const Instagram340& other);
		void createUser(const std::string& username, const std::string& email, const std::string& password,
						const std::string& bio, const std::string& profilePicture, const bool isCreator, const bool verified);
		void displayNthUser(const int& n);
		std::shared_ptr<User> getUser(const int& indexK);
		void displayUsers();
};
#include "Instagram340.cpp"
#endif