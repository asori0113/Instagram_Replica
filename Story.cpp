#include "Story.h"
#include <string>
#include <iostream>

/*
@param expiration: calculated by the calling class before it is passed to the constructor

*/

Story::Story(std::string title, int timeSTMP, int likes, std::string url, int postNo, int duration, int expiration) : maxDuration(60), expirationTime(expiration) {
	Post(title, timeSTMP, likes, url, postNo, duration);

}

int Story::getExpirationTime() {
	return expirationTime;
}

void Story::editPost() {
	std::cout << "Filter, music, stickers and effects have been added to the post." << "\n";
}

void Story::display() {
	std::cout << "===========================\n";
	std::cout << "POST INFO: \n\n";
	std::cout << "Title: " << this->getTitle() << "\n";
	std::cout << "Time Stamp: " << this->getTimeStamp << "\n";
	std::cout << "Likes: " << this->getNumLikes() << "\n";
	std::cout << "URL: " << this->getPostURL() << "\n";
	std::cout << "Duration: " << this->getPostDuration() << "\n";

	// Put everything above in Post's display() method

	std::cout << "Expires in " << getExpirationTime() << "\n";


}



// When displaying a story, use this to compute expected expiration time: timeToExpiration
// Define this as a private function 
int Story::computeTimeToExpiration() const {
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour;

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - Post::time_stamp;
	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

	return timeToExpiration;
}




