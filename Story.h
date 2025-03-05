

#ifndef STORY_
#define STORY_
class Story : public Post // THIS AINT WORKING?!?!? WHY????
{
private: 
	int expirationTime;
	int maxDuration;
	int Post::computeTimeToExpiration() const;

public:
	Story(std::string title, int timeSTMP, int likes, std::string url, int postNo, int duration, int expiration);
	int getExpirationTime();
	void editPost();
	void display();

};
#include "Post.cpp"
#include <string>
#include "Story.cpp"
#endif

