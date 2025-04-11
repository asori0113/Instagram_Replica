#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Instagram340.h"
#include <limits>


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
			cin >> url;


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
					cout << "Invalid input. Write only 'true' or 'false'\n";
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

			cout << "Which post would you like to delete? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > user.get()->getPostCount() || k < 1) {
				cout << "Error: You only have " << user.get()->getPostCount() << " post(s)." << "Please enter another number.\n";
				cin >> k;

			}

			user.get()->deletePost(k);

			break;
		}

		case 8: {
			int k;
			string newTitle;


			cout << "Which post would you like to edit? Enter the post number: (e.g Enter '1' for the 1st post) \n";
			cin >> k;

			while (k > user.get()->getPostCount() || k < 1) {
				cout << "Error: You only have " << user.get()->getPostCount() << " post(s)." << "Please enter another number.\n";
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

void landingPage(int& choice, Instagram340& instagram) {

	if (choice == 1) {
		std::cout << "CREATE AN ACCOUNT. Be sure to remember the order you created your accounts:\n\n" << endl;
		
		std::string newUsername;
		std::string newEmail;
		std::string newPassword;
		std::string newBio;
		std::string newProfilePicture;
	
		std::cout << "\nEnter Username:";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(std::cin, newUsername);

		std::cout << "\nEnter email: ";
		getline(std::cin, newEmail);

		std::cout << "\nEnter Password: ";
		getline(std::cin, newPassword);

		std::cout << "\nEnter bio: ";
		getline(std::cin, newBio);

		std::cout << "\nEnter Profile Picture Path: ";
		getline(std::cin, newProfilePicture);

		std::string userType;
		
		bool isCreator = false;
		bool isValid = false;
		bool creatorVerified = false;
		do {
			std::cout << "Account Type: Enter ('true' if a Creator) || Enter ('false' if Personal)\n " << std::endl;
			std::cin >> userType;

			if (userType.compare("true") == 0) {
				isValid = true;
				isCreator = true;

				std::string creatorStatus;
				std::cout << "Is this creator verified? Enter ('true' || 'false')" << std::endl;
				std::cin >> creatorStatus;

				
				if (creatorStatus.compare("true") == 0) {
					creatorVerified = true;
				}

			}
			else if (userType.compare("false") == 0) {
				isValid = true;
				isCreator = false;
			}

			else {
				std::cout << "Invalid input. Write only 'true' or 'false'\n";
			}

		} while (!isValid);

		instagram.createUser(newUsername, newEmail, newPassword, newBio, newProfilePicture, isCreator, creatorVerified);
		
	}
	else if (choice == 2) {
		int userNum;
		std::cout << "\nWhich User would you like to get (by index):";
		std::cin >> userNum;
		std::shared_ptr<User> currentUser;
		if (instagram.getUser(userNum) != nullptr) {
			currentUser = instagram.getUser(userNum);
			displayUserManu(currentUser);
		}
		else {
			std::cout << "\nUser does not Exist";
			choice = 0;

		}
	}
	else {
		std::cout << "\nInvalid option";
	}
}

int main() {
	Instagram340 instagram;
	bool exitProgram = false;
	do {
		cout << "Welcome to Instagram340. What do you want to do?\n";
		int choice;

		std::cout <<"Options: \n"
			<< "1. Create Account\n"
			<< "2. Sign In\n"
			<< "0. Exit Program\n";
		cin >> choice;

		if (choice != 0) {
			landingPage(choice, instagram);
		}

		else if (choice == 0) {
			exitProgram = true;
		} 

		else {
			cout << "Error.\n";
		}
		
	}

	while (!exitProgram);
	return 0;



}
