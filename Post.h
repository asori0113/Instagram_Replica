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
#include <memory>

class Post {

private:
	std::string title;
	std::string url;
	int timeStamp;
	int numLikes;
	int postDuration;
	void setNumLikes();

	
public:
	Post();
	Post(std::string postTitle, std::string url, int duration);
	bool operator==(const Post& otherPost) const;
	virtual std::shared_ptr<Post> clone() const;
	virtual void display();
	virtual void editPost();

	// Setters

	void editTitle(std::string newTitle);
	//void setTimeStamp();
	//void setPostURL(std::string newURL);
	//void setPostNum(int num);
	void setDuration(int newDuration);

	// Getters

	std::string getTitle() const;
	std::string getURL() const;
	int getTimeStamp() const;
	int getNumLikes() const;
	int getDuration() const;
	
	
};
#include "Post.cpp"
#endif