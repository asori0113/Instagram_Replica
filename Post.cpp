// TO DO: #include all the standard libraries and your own libraries here
#include <chrono>
#include "Post.h"

// TO DO: function implementations
// When creating a post, you may use this code to set time stamp
auto time_stamp = std::chrono::steady_clock::now();



// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}





