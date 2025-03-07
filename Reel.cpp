#include "Reel.h"
#include <string>
#include <iostream>

Reel::Reel() : maxDuration(90) {
    Post("","",-1,-1,-1);
}

Reel::Reel(std::string postTitle, std::string postURL, int likes, int postNo, int duration) : maxDuration(90){
    //If duration exceeds maxDuration, keep prompting for a new duration. 
	do {
		std::cout << "Error: Video duration must be at most 90 seconds. \n";
		std::cout << "Please input new video duration: \n";
		std::cin >> duration;
	} while (duration > maxDuration);

    Post(postTitle, postURL, likes, postNo, duration);
}


void Reel::editPost() {
    std::cout << "*****Filter, AR effects, and music have been added to the post.\n";
}

