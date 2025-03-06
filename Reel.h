#ifndef REEL_
#define REEL_
//public or private inheritance
#include <string>

class Reel : public Post {
private:
    int maxDuration;
public:
    Reel();

    Reel(std::string postTitle, std::string postURL, int likes, int postNo, int duration);
    void display() override;
    void editPost() override;
};

#include "Reel.cpp"
#endif