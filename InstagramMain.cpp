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
void displayUserManu(shared_ptr<User> user) {
	int userChoice = 0;
	do {
		cout << "\n Hi, " << user.get()->getUsername() << ", what would you like to do:\n"
			<< "1. Display Profile\n"
			<< "2. Modify Password\n"
			<< "3. Create Post\n"
			<< "4. Display All Posts\n"
			<< "5. Display Kth Post\n"
			<< "6. Modify Post\n"
			<< "7. Delete Post\n"
			<< "8. Edit Post\n"
			<< "0. Logout\n"
			<< "Choice: ";
		cin >> userChoice;

		switch (userChoice) {
		case 1: {
			user.get()->displayProfile();
			break;
		}
		case 2: {
			std::string newPass;
			cout << "What is your new password?\n";
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

			cout << "What would you like to call it \n";
			cin >> title;

			cout << "Media Address(create your own):\n";
			cin >> url ;


			do {
				cout << "Type ('true' if it's a reel) || Type ('false' if it's a story)\n " << endl;
				cin >> postType;

				if (postType.compare("true") == 0) {
					isValid = true;
					isReel = true;
				}
				else if (postType.compare("false") == 0) {
					isValid = true;
					isReel = false;
				}

				else {
					cout << "Invalid input. Write only 'reel' or 'story'\n";
				}

			} while (!isValid);

			cout << "What is the duration? Enter a number (1-90) for Reel || Enter a number (1-60) for Story.\n";
			cin >> duration;
			user.get()->createPost(title, url, duration, isReel);

			break;
		}
		case 4: {
			cout << "DISPLAYING ALL POSTS \n";
			user.get()->displayPosts();

			break;
		}

		case 5: {
			int k;

			cout << "Which post would you like to display? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > user.get()->getPostCount() || k < 1) {
				cout << "Error: You only have " << user.get()->getPostCount() << " post(s)." << "Please enter another number.\n";
				cin >> k;

			}

			user.get()->displayNthPost(k);
			break;
		}
		case 6: {
			int k;
			cout << "Which post would you like to modify? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > user.get()->getPostCount() || k < 1) {
				cout << "Error: You only have " << user.get()->getPostCount() << " post(s)." << "Please enter another number.\n";
				cin >> k;

			}

			user.get()->modifyNthPost(k);

			break;
		}
		case 7: { // Delete Post
			int k;
			int postCount = user.get()->getPostCount();
			cout << "Which post would you like to delete? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > postCount || k < 1) {
				cout << "Error: You only have " << postCount << " post(s)." << "Please enter another number.\n";
				cin >> k;

			}

			user.get()->deletePost(k);
			break;
		}

		case 8: {
			int k;
			string newTitle;
			int postCount = user.get()->getPostCount();

			cout << "Which post would you like to edit? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > postCount || k < 1) {
				cout << "Error: You only have " << postCount << " post(s)." << "Please enter another number.\n";
				cin >> k;

			}

			cout << "What would you like to name it?\n";
			cin >> newTitle;

			
			user.get()->editNthPost(newTitle, k);
			cout << "Post has been edited \n";

			break;
		}

		case 0: {
			cout << "Logging you out." << endl;
			break;
		}
		default:
			cout << "Invalid choice. Please try again." << endl;
		}

	} while (userChoice != 0);
}


int main() {
	Instagram340 instagram;

	cout << "\n Welcome to Instagram340:" << endl;

	string username;
	string email;
	string password;
	string bio;
	string profilePicture;

	cout << "Enter Username: ";
	getline(cin, username);

	cout << "\nEnter email: ";
	getline(cin, email);

	cout << "\nEnter Password: ";
	getline(cin, password);

	cout << "\nEnter bio: ";
	getline(cin, bio);

	cout << "\nEnter Profile Picture Path: ";
	getline(cin, profilePicture);

	instagram.createUser(username, email, password, bio, profilePicture);
	// Retrieve the user 
	shared_ptr<User> currentUser = instagram.getUser(1);
	displayUserManu(currentUser);
	return 0;


}