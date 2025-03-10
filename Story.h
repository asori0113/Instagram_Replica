

#ifndef STORY_
#define STORY_

#include "Post.h" // From what I googled, you have to include the header file of the base class. 
#include <string>

class Story : public Post {
private:
	int expirationTime;
	int maxDuration;
	int computeTimeToExpiration();

public:
	Story();
	Story(std::string postTitle, std::string postURL, int duration);
	int getExpirationTime();

	// Override keyword is a failsafe. 
	void display() override;
	void editPost() override;

};
#include "Story.cpp"
#endif

