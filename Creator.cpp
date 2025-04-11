#include "Creator.h"

Creator::Creator() : isVerified(false) {

}

Creator::Creator(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture, bool status) : User(name, emailAdd, password, bioStr, profilePicture), isVerified(status)
{

}

Creator::~Creator() {
	userPosts.clear();
}

Creator::Creator(const Creator& other): User(other.getUsername(), other.getEmail(), other.getPass(), other.getBio(), other.getProfilePicture()) , isVerified(other.checkVerification()){
	if (!other.userPosts.isEmpty()) {
		//No need for make_shared since clone() takes care of it.
		userPosts.add(other.userPosts.findKthItem(1)->getItem().get()->clone());

		for (int postNum = 2; postNum <= getPostCount(); ++postNum) {
			userPosts.append(other.userPosts.findKthItem(postNum)->getItem().get()->clone());
		}
	
	}
}

Creator& Creator::operator=(const Creator& other) {
	if (this != &other) {
		userPosts.clear();


		if (!other.userPosts.isEmpty()) {
			userPosts.add(other.userPosts.findKthItem(1)->getItem().get()->clone());
		}

		for (int postNum = 2; postNum <= other.userPosts.getCurrentSize(); ++postNum) {
			userPosts.append(other.userPosts.findKthItem(postNum)->getItem().get()->clone());
		}

		User(other.getUsername(), other.getEmail(), other.getPass(), other.getBio(), other.getProfilePicture());
		isVerified = other.checkVerification();

	}
	return *this;
}

std::shared_ptr<User> Creator::clone() const {
    return std::make_shared<Creator>(*this);
}

void Creator::makeVerified(bool status)
{
    isVerified = status;
    
}

bool Creator::checkVerification() const
{
    return isVerified;
}

void Creator::displayProfile()
{
	User::displayProfile();
	std::cout << "Type: Creator\n";
	std::cout << "This Creator is " << (isVerified ? "verified\n" : "unverified\n");

}


