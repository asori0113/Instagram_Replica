// TO DO: #include all the standard libraries and your own libraries here
#include "Post.h"
#include <iostream>
#include <string>


Post::Post() : title(""), timeStamp(-1), numLikes(-1), url(""), postNum(-1), postDuration(-1) {} // default constructor



// Main constructor to use. Initializes title, url, likes, postNum, and duration. Sets time stamp upon instantiation. 
Post::Post(std::string postTitle, std::string postURL, int likes, int postNo, int duration) : title(postTitle), url(postURL), numLikes(likes), postNum(postNo), postDuration(duration)
{
	// Code provided for setting time stamp 
	auto time_stamp = std::chrono::steady_clock::now();
	timeStamp = std::chrono::duration_cast<std::chrono::seconds>(time_stamp.time_since_epoch()).count();
}

// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}

void Post::display() {
	// Not sure whether to use "this" notation when calling functions

	std::cout << "===========================\n";
	std::cout << "POST INFO: \n\n";
	std::cout << "Title: " << getTitle() << "\n";
	std::cout << "Time Stamp: " << getTimeStamp() << "\n";
	std::cout << "Likes: " << getNumLikes() << "\n";
	std::cout << "URL: " << getURL() << "\n";
	std::cout << "Duration: " << getDuration() << "\n";

}

void Post::editPost() {
	std::cout << "===========================\n";
	std::cout << "You have edited your post. \n";
	std::cout << "===========================\n";
}

// Setters

void Post::editTitle(std::string newTitle) {
	title = newTitle;
}



void Post::setNumLikes(int likes) {
	numLikes = likes;
}

//void Post::setTimeStamp() {}
//void Post::setPostURL(std::string newURL) {}
//void Post::setPostNum(int num) {}
// 
//void Post::setDuration(int newDuration) {
//	duration = newDuration;
//}

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

int Post::getPostNum() {
	return postNum;
}
	
int Post::getDuration() {
	return postDuration;
}