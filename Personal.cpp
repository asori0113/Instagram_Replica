#include "Personal.h"

Personal::Personal() : draftCount(0){

}

Personal::~Personal() {

}

Personal::Personal(int Count) : draftCount(Count) {

}

Personal::Personal(const Personal& other) {

}

Personal& Personal::operator=(const Personal& other) {

}

std::shared_ptr<User> Personal::clone() const {
	return std::make_shared<Personal>(*this);
}



void Personal::displayProfile() {
    std::cout << "Type: Personal\n";
}

void Personal::createDraft() {
	std::cout << "Created Draft\n";
	draftCount++;
}

int Personal::getDraftCount() {	
	return draftCount;
}