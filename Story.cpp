#include "Story.h"
#include <string>
#include <iostream>

Story::Story() : maxDuration(60) {
	Story::Post("", "", -1, -1, -1);
	expirationTime = computeTimeToExpiration();

}

// Main constructor. Calls parent class to initialize title, url, likes, postNum, duration. Initializes maxDuration to 60. 
Story::Story(std::string postTitle, std::string postURL, int likes, int postNo, int duration) : maxDuration(60) 
{
	//If duration exceeds maxDuration, keep prompting for a new duration. 
	do {
		std::cout << "Error: Video duration must be at most 60 seconds. \n";
		std::cout << "Please input new video duration: \n";
		std::cin >> duration;
	} while (duration > maxDuration);

	Story::Post(postTitle, postURL, likes, postNo, duration);
	expirationTime = computeTimeToExpiration();
}

//Why is there a red squiggle on a BLANK line?

int Story::getExpirationTime() {
	return expirationTime;
}

// Please check whether  editPost() and display() actually override the same methods in Post class.
void Story::editPost() {
	std::cout << "*****Filter, music, stickers and effects have been added to the post." << "\n";
}

// Call parent class display and print whether the story expired or when it expires
void Story::display() {

	Post::display();

	if (expirationTime == 0) {
		std::cout << " This Story has expired. \n";
	}

	else {
		std::cout << "Expires in " << expirationTime << "\n";
	}
	
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
    