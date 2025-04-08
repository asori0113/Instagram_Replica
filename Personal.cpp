#include "Personal.h"

Personal::Personal() {

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