#include "Reel.h"
#include <string>
#include <iostream>

Reel::~Reel() {

}

//Default Constructor
Reel::Reel() : maxDuration(90) {
}

//Copy Constructor
Reel::Reel(const Reel& otherReel) : Post(otherReel.getTitle(), otherReel.getURL(), otherReel.getDuration()), maxDuration(90) {

}


//Clone function for polymorphic copying. Basically: Get a clone of this object to be managed by a separate shared pointer.

/*
	Clone() is a "polymorphic" copy constructor. Dynamically allocates a new copy of this object, using the information of itself to instantiate it.
	Returns the newly allocated Story object managed by a shared ptr of type Post.
	Naturally, we end up needing to implement the copy constructor of Reel since we are passing the object pointed to by "this".
*/
std::shared_ptr<Post> Reel::clone() const
{
	return std::make_shared<Reel>(*this);
}

Reel::Reel(std::string postTitle, std::string postURL, int duration) : Post(postTitle, postURL, duration), maxDuration(90) {

	bool invalid = (duration > maxDuration) || (duration < 1);
	//If duration exceeds maxDuration, keep prompting for a new duration. 
	if (invalid) {
		int newDuration;

		while (invalid) {
			std::cout << "===========================\n\n";
			std::cout << "Error: Video duration must be at most 90 seconds. Please input new video duration: \n";
			std::cin >> newDuration;

			invalid = (newDuration > maxDuration) || (newDuration < 1);

		}

		Post::setDuration(newDuration);
	}
}

void Reel::editPost() {
	std::cout << "EDITING POST\n";
	std::cout << "*****Filter, AR effects, and music have been added to the post.\n";
}