#include "Reel.h"
#include <string>
#include <iostream>


Reel::Reel() : maxDuration(90) {
}

Reel::Reel(std::string postTitle, std::string postURL, int duration) : Post(postTitle, postURL, duration), maxDuration(90) {

	//If duration exceeds maxDuration or is less than 1, keep prompting for a new duration.
		while ((duration > maxDuration) || (duration < 1)) {
			std::cout << "===========================\n\n";
			std::cout << "Error: Video duration must be at most 90 seconds. Please input new video duration: \n";
			std::cin >> duration;
			
		}

		Post::setDuration(duration);
}

void Reel::editPost() {
	std::cout << "EDITING POST\n";
	std::cout << "*****Filter, AR effects, and music have been added to the post.\n";
}