#include "Story.h"
#include <string>
#include <iostream>

//Default Constructor
Story::Story() : maxDuration(60) {
	expirationTime = computeTimeToExpiration();

}
//Copy Constructor


Story::Story(const Story& otherStory) :Post(otherStory.getTitle(), otherStory.getURL(), otherStory.getDuration()), maxDuration(60), expirationTime(otherStory.getExpirationTime()) {

}

/*
	Clone() is a "polymorphic" copy constructor. Dynamically allocates a new copy of this object, using the information of itself to instantiate it.
	Returns the newly allocated Story object managed by a shared ptr of type Post. 
	Naturally, we end up needing to implement the copy constructor of Story since we are passing the object pointed to by "this". 
*/

std::shared_ptr<Post> Story::clone() const
{
	return std::make_shared<Story>(*this);
}

// Main constructor. Calls parent class to initialize title, url, likes, postNum, duration. Initializes maxDuration to 60. 
Story::Story(std::string postTitle, std::string postURL, int duration) : Post(postTitle, postURL, duration), maxDuration(60)
{
	bool invalid = (duration > maxDuration) || (duration < 1);
	//If duration exceeds maxDuration, keep prompting for a new duration. 
	if (invalid) {
		int newDuration;

		while (invalid) {
			std::cout << "===========================\n\n";
			std::cout << "Error: Video duration must be at most 60 seconds. Please input new video duration: \n";
			std::cin >> newDuration;

			invalid = (newDuration > maxDuration) || (newDuration < 1);

		}

		Post::setDuration(newDuration);
	}

	expirationTime = computeTimeToExpiration();
}




int Story::getExpirationTime() const {
	return expirationTime;
}
void Story::editPost() {
	std::cout << "EDITING POST\n";
	std::cout << "*****Filter, music, stickers and effects have been added to the post." << "\n";
}

// Call parent class display and print whether the story expired or when it expires
void Story::display() {

	Post::display();

	if (expirationTime == 0) {
		std::cout << " This Story has expired. \n";
	}

	else {
		std::cout << "Expires in " << expirationTime << "s\n";
	}

	std::cout << "===========================\n\n\n";
	
}

//Function provided to compute expiration time
int Story::computeTimeToExpiration() {

	//auto time_stamp provided to set time stamp
	auto time_stamp = std::chrono::steady_clock::now();

	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour;

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - time_stamp;
	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

	return timeToExpiration;
}




