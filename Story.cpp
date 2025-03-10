#include "Story.h"
#include <string>
#include <iostream>

Story::Story() : maxDuration(60) {
	expirationTime = computeTimeToExpiration();

}

// Main constructor. Calls parent class to initialize title, url, likes, postNum, duration. Initializes maxDuration to 60. 
Story::Story(std::string postTitle, std::string postURL, int duration) : Post(postTitle, postURL, duration), maxDuration(60)
{
	//If duration exceeds maxDuration, keep prompting for a new duration. 
	if (duration > maxDuration && duration <= 0 ) {

		while (duration > maxDuration && duration <= 0) {
			std::cout << "===========================\n\n";
			std::cout << "Error: Video duration must be at most 90 seconds and at least 0. Please input new video duration: \n";
			std::cin >> duration;

		}

		Post::setDuration(duration);
	}

	expirationTime = computeTimeToExpiration();
}

int Story::getExpirationTime() {
	return expirationTime;
}

// Please check whether  editPost() and display() actually override the virtual methods in Post class.
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