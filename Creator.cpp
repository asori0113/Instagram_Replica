#include "Creator.h"

Creator::Creator() : isVerified(false) {

}

Creator::Creator(const std::string& name, const std::string& emailAdd, const std::string& password, const std::string& bioStr, const std::string& profilePicture) : User(name, emailAdd, password, bioStr, profilePicture), isVerified(false)
{
}

Creator::~Creator() {

}

Creator::Creator(const Creator& other) {

}

Creator& Creator::operator=(const Creator& other) {

}

std::shared_ptr<User> Creator::clone() const {
    return std::make_shared<Creator>(*this);
}

//Dont forget to call this when creating a User. Or maybe we can automatically determine it using an arbitrary standard...
void Creator::setVerification(bool status)
{
    isVerified = status;
}

bool Creator::checkVerification()
{
    return isVerified;
}

void Creator::displayProfile()
{
}
