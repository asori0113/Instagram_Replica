// TO DO: #include all the standard libraries and your own libraries here
// To DO: define the class Post with the necessary functions' prototypes and data fields
// This is a function that allows you to compare two posts based on their title. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:
#include <string>
#include <chrono>
#ifndef POST_
#define POST_
class Post {
private:
	std::chrono::duration<double> time_stamp;
	int postDuration;
	std::string title;
	int computeTimeToExpiration() const;
	
public:
	Post(std::string title, int timeSTMP, int likes, std::string url, int postNo, int duration);
	bool operator==(const Post& otherPost) const;
	virtual void editPost();
	virtual void display();
	void setTimeStamp();
	int getTimeStamp();
	
	
};
#include "Post.cpp"
#endif