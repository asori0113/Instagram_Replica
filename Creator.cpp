#include "Creator.h"

Creator::Creator() {

}

Creator::~Creator() {

}

Creator::Creator(const Creator& other) {

}

Creator& Creator::operator=(const Creator& other) {

}

std::shared_ptr<User> Creator::clone() const {
    return std::make_shared<Creator> (*this);
}