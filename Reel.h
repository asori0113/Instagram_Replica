
#ifndef REEL_
#define REEL_
//public or private inheritance
#include <string>
#include "Post.h"

class Reel : public Post {
private:
    int maxDuration;
public:
    Reel();
    Reel(std::string postTitle, std::string postURL, int duration);
    void editPost() override;
};
#include "Reel.cpp"
#endif
