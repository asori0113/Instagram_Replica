
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
	~Post();
	Post();
	Post(const Post& post2);
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