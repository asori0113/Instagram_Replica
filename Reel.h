#ifndef REEL_
#define REEL_
//public or private inheritance

class Reel : public Post {
private:
    int maxDuration;
public:
    void editPost();
};

#include "Reel.cpp"
#endif