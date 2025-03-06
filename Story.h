#ifndef STORY_
#define STORY_

#include "Post.h"
#include <string>

class Story : public Post {
private:
	int expirationTime;
	int maxDuration;
	int computeTimeToExpiration();

public:
	Story();
	Story(std::string postTitle, std::string postURL, int likes, int postNo, int duration);
	int getExpirationTime();
	void display();
	void editPost();

};
#include "Story.cpp"
#endif