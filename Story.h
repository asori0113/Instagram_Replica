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
	~Story() override;
	Story();
	Story(const Story& otherStory);
	Story& operator=(const Story& other);
	Story(std::string postTitle, std::string postURL, int duration);
	int getExpirationTime() const;

	// Override keyword is a failsafe. 
	std::shared_ptr<Post> clone() const override;
	void display() override;
	void editPost() override;

};
#include "Story.cpp"
#endif