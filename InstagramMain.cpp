#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Instagram340.h"


using namespace std;

/**
 *
 * Displays the application's main menu
 * pre create a new object of type User
 * @param user object to interact with
 *
 * */
void displayUserManu(shared_ptr<User>& user, Instagram340 instagram) {
	int userChoice = 0;
	do {
		std::cout << "\n Hi, " << user.get()->getUsername() << ", what would you like to do:\n"
			<< "1. Display Profile\n"
			<< "2. Modify Password\n"
			<< "3. Create Post\n"
			<< "4. Display All Posts\n"
			<< "5. Display Kth Post\n"
			<< "6. Modify Post\n"
			<< "7. Delete Post\n"
			<< "8. Edit Post\n"
			<< "9. Create A New Account or Retreive Account\n"
			<< "0. Logout\n"
			<< "Choice: ";
		std::cin >> userChoice;

		switch (userChoice) {
		case 1: {
			user.get()->displayProfile();
			break;
		}
		case 2: {
			std::string newPass;
			std::cout << "What is your new password?\n";
			cin >> newPass;

			user.get()->modifyPassword(newPass);
			break;
		}
		case 3: {
			string title;
			string url;
			int duration;
			string postType;
			bool isReel = false;
			bool isValid = false;

			std::cout << "What would you like to call it \n";
			cin >> title;

			std::cout << "Media Address(create your own):\n";
			cin >> url ;


			do {
				std::cout << "Type ('true' if it's a reel) || Type ('false' if it's a story)\n " << endl;
				std::cin >> postType;

				if (postType.compare("true") == 0) {
					isValid = true;
					isReel = true;
				}
				else if (postType.compare("false") == 0) {
					isValid = true;
					isReel = false;
				}

				else {
					std::cout << "Invalid input. Write only 'reel' or 'story'\n";
				}

			} while (!isValid);

			std::cout << "What is the duration? Enter a number (1-90) for Reel || Enter a number (1-60) for Story.\n";
			std::cin >> duration;
			user.get()->createPost(title, url, duration, isReel);

			break;
		}
		case 4: {
			std::cout << "DISPLAYING ALL POSTS \n";
			user.get()->displayPosts();

			break;
		}

		case 5: {
			int k;

			std::cout << "Which post would you like to display? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			std::cin >> k;

			while (k > user.get()->getPostCount() || k < 1) {
				std::cout << "Error: You only have " << user.get()->getPostCount() << " post(s)." << "Please enter another number.\n";
				std::cin >> k;

			}

			user.get()->displayNthPost(k);
			break;
		}
		case 6: {
			int k;
			std::cout << "Which post would you like to modify? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > user.get()->getPostCount() || k < 1) {
				std::cout << "Error: You only have " << user.get()->getPostCount() << " post(s)." << "Please enter another number.\n";
				cin >> k;

			}

			user.get()->modifyNthPost(k);

			break;
		}
		case 7: { // Delete Post
			int k;

			std::cout << "Which post would you like to delete? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > user.get()->getPostCount() || k < 1) {
				std::cout << "Error: You only have " << user.get()->getPostCount() << " post(s)." << "Please enter another number.\n";
				cin >> k;

			}

			user.get()->deletePost(k);

			break;
		}

		case 8: {
			int k;
			string newTitle;


			std::cout << "Which post would you like to edit? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > user.get()->getPostCount() || k < 1) {
				std::cout << "Error: You only have " << user.get()->getPostCount() << " post(s)." << "Please enter another number.\n";
				std::cin >> k;

			}

			std::cout << "What would you like to name it?\n";
			std::cin >> newTitle;

			
			user.get()->editNthPost(newTitle, k);
			std::cout << "Post has been edited \n";

			break;
		}
		case 0: {
			int landingChoice;

			do
			{
				std::cout << "Options: \n"
				<< "1. Create Account\n"
				<< "2. Retreive Account\n"
				<< "3. Logout\n";
			std::cin >> landingChoice;
			instagram.landingPage(landingChoice);
			
			} while (landingChoice != 1,2,3);

			displayUserManu(user, instagram);
			
			
		}
		default:
			std::cout << "Invalid choice. Please try again." << endl;
		}

	} while (userChoice != 0);
}


int main() {
	Instagram340 instagram;

	std::cout << "\n Welcome to Instagram340:" << endl;

	string username;
	string email;
	string password;
	string bio;
	string profilePicture;

	std::cout << "Enter Username: ";
	getline(cin, username);

	std::cout << "\nEnter email: ";
	getline(cin, email);

	std::cout << "\nEnter Password: ";
	getline(cin, password);

	std::cout << "\nEnter bio: ";
	getline(cin, bio);

	std::cout << "\nEnter Profile Picture Path: ";
	getline(cin, profilePicture);

	instagram.createUser(username, email, password, bio, profilePicture);


	// Retrieve the user 
	shared_ptr<User> currentUser = instagram.getUser(1);
	displayUserManu(currentUser, instagram);
	return 0;


}