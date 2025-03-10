
#include "Post.h"
#include <iostream>
#include <cstdlib>   
#include <ctime> 

Post::~Post() {

}

Post::Post() : title(""), timeStamp(-1), numLikes(-1), url(""), postDuration(-1) {} // default constructor

// Main constructor to use. Initializes title, url, likes, postNum, and duration. Sets time stamp upon instantiation. 
Post::Post(std::string postTitle, std::string postURL, int duration) : title(postTitle), url(postURL), postDuration(duration)
{
	// Code provided for setting time stamp 
	auto time_stamp = std::chrono::steady_clock::now();
	timeStamp = std::chrono::duration_cast<std::chrono::seconds>(time_stamp.time_since_epoch()).count();
	setNumLikes();
}

// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}

void Post::display() {

	std::cout << "===========================\n";
	std::cout << "POST INFO: \n\n";
	std::cout << "Title: " << getTitle() << "\n";
	std::cout << "Time Stamp: " << getTimeStamp() << "\n";
	std::cout << "Likes: " << getNumLikes() << "\n";
	std::cout << "URL: " << getURL() << "\n";
	std::cout << "Duration: " << getDuration() << "s\n\n";


}

void Post::editPost() {
	std::cout << "===========================\n";
	std::cout << "You have edited your post. \n";
	std::cout << "===========================\n\n\n";

}

// Setters

void Post::editTitle(std::string newTitle) {
	title = newTitle;
}



void Post::setNumLikes() {
	std::srand(std::time(0)); // Seed random number generator
	int random_number = std::rand() % 100 + 1; // Range [1, 100]
	numLikes = random_number;
}


void Post::setDuration(int newDuration) {
	postDuration = newDuration;
}

// Getters

std::string Post::getTitle() {
	return title;
}
std::string Post::getURL() {
	return url;
}

int Post::getTimeStamp() {
	return timeStamp;
}

int Post::getNumLikes() {
	return numLikes;
}
	
int Post::getDuration() {
	return postDuration;
}
