#include "Personal.h"

Personal::Personal() {

}

Personal::Personal(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture) : User(name, emailAdd,password,bioStr,profilePicture)
{
}

Personal::~Personal() {
	userPosts.clear();
}

Personal::Personal(const Personal& other) : User(other.getUsername(), other.getEmail(), other.getPass(), other.getBio(), other.getProfilePicture()) {
	if (!other.userPosts.isEmpty()) {
		//No need for make_shared since clone() takes care of it.
		userPosts.add(other.userPosts.findKthItem(1)->getItem().get()->clone());

		for (int postNum = 2; postNum <= getPostCount(); ++postNum) {
			userPosts.append(other.userPosts.findKthItem(postNum)->getItem().get()->clone());
		}

	}

}


Personal& Personal::operator=(const Personal& other) {

	if (this != &other) {
		userPosts.clear();


		if (!other.userPosts.isEmpty()) {
			userPosts.add(other.userPosts.findKthItem(1)->getItem().get()->clone());
		

		for (int postNum = 2; postNum <= other.userPosts.getCurrentSize(); ++postNum) {
			userPosts.append(other.userPosts.findKthItem(postNum)->getItem().get()->clone());
		}

		}

		User(other.getUsername(), other.getEmail(), other.getPass(), other.getBio(), other.getProfilePicture());

	}
	return *this;
}

std::shared_ptr<User> Personal::clone() const {


	return std::make_shared<Personal>(*this);


}


void Personal::displayProfile() {

	User::displayProfile();
	std::cout << "Type: Personal\n";
	std::cout << "Personal Account was intended to have a collection of memorable posts. To be implemented later.\n";


}


