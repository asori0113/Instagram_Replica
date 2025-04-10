#include "Personal.h"

Personal::Personal() {

}

Personal::Personal(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture) : User(name, emailAdd,password,bioStr,profilePicture)
{
}

Personal::~Personal() {

}

Personal::Personal(const Personal& other) {

}


Personal& Personal::operator=(const Personal& other) {


}

std::shared_ptr<User> Personal::clone() const {


	return std::make_shared<Personal>(*this);


}

void Personal::createPrivatePost(std::string postTitle, std::string url, int duration, bool isReel)
{
}

void Personal::displayPosts()
{
}

void Personal::displayProfile() {

	User::displayProfile();
	std::cout << "Type: Personal\n";


}


//This should display nth private post too. Just make this call a method that displays those. 
void Personal::displayNthPost(int n)
{
}
