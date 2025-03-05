// TO DO: #include all the standard libraries and your own libraries here
// To DO: define the class Post with the necessary functions' prototypes and data fields
// This is a function that allows you to compare two posts based on their title. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:

#ifndef POST_
#define POST_

#include <string>
#include <chrono>

class Post {

private:
	std::string title;
	std::string url;
	int timeStamp;
	int numLikes;
	int postNum;
	int postDuration;

	
public:
	Post();
	Post(std::string postTitle, std::string url, int likes, int postNo, int duration);
	bool operator==(const Post& otherPost) const;
	virtual void display();
	virtual void editPost();

	// Setters

	void editTitle(std::string newTitle);
	void setNumLikes(int likes);
	//void setTimeStamp();
	//void setPostURL(std::string newURL);
	//void setPostNum(int num);
	//void setDuration(int newDuration);

	// Getters

	std::string getTitle();
	std::string getURL();
	int getTimeStamp();
	int getNumLikes();
	int getPostNum();
	int getDuration();
	
	
};
#include "Post.cpp"
#endif