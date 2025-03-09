#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Instagram340.h"
#include "User.h"


using namespace std;

/**
 *
 * Displays the application's main menu
 * pre create a new object of type User
 * @param user object to interact with
 *
 * */
void displayUserManu(User& user) {
	int userChoice = 0;
	do {
		cout << "\n Hi, " << user.getUsername() << ", what would you like to do:\n"
			<< "1. Display Profile\n"
			<< "2. Modify Password\n"
			<< "3. Create Post\n"
			<< "4. Display All Posts\n"
			<< "5. Display Kth Post\n"
			<< "6. Modify Post\n"
			<< "7. Delete Post\n"
			<< "0. Logout\n"
			<< "Choice: ";
		cin >> userChoice;

		switch (userChoice) {
		case 1: {
			user.displayProfile();
			break;
		}
		case 2: {
			// TO DO: ask for new password and update user's password
			std::string newPass;
			cout << "What is your new password?\n";
			cin >> newPass;

			user.modifyPassword(newPass);
			break;
		}
		case 3: {
			// TO DO: ask user to choose between Reel and Story, ask them to input post details:
			//        (title, media URL, video length in seconds)
			//        Your program should set the time stamp to current time (code provided in Post.cpp) 
			// then create the post and add it to the user's posts
			break;
		}
		case 4: {
			// TO DO: display all user's posts
			//        You may re-use code from class demo
			cout << "DISPLAYING ALL POSTS \n";
			user.displayPosts();

			break;
		}
		case 5: {
			// TO DO: ask the user for a value k
			// Find the Kth post, if k > Linked Bag size, 
			//    return an error message that includes the size of the Linked Bag
			int value;
			cout << "What value nth post would you like to access: \n";
			cin >> value;

			user.displayNthPost(value);
			break;
		}
		case 6: {
			// TO DO: ask the user for the index of the post they want to modify and the new title
			// Find the post, then update the title. 
			// If index > Linked Bag size, 
			//    return an error message that includes the size of the Linked Bag
			string title;
			int postnum;
			cout << "\nWhich post would you like to modify: ";
			cin >> postnum;

			cout << "\nWhat would you like to name it: ";
				user.modifyNthPost(title, postnum);
			break;
		}
		case 7: {
			// TO DO: ask the user for the index of the post they want to delete 
			// Find the post, then remove it from the list. 
			// If index > LinkedBag size, 
			//    return an error message that includes the size of the Linked Bag
			break;
		}
		case 8: {

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
	cin >> username;

	cout << "\nEnter email: ";
	cin >> email;

	cout << "\nEnter Password: ";
	cin >> password;

	cout << "\nEnter bio: ";
	cin >> bio;

	cout << "Enter Profile Picture Path: ";
	cin >> profilePicture;

	// call instagram createUser function 
	// replace /*...*/ with the right parameters
	instagram.createUser(username, email, password,
		bio, profilePicture);

	// Retrieve the user 
	User currentUser = instagram.getUser(1);
	displayUserManu(currentUser);

	return 0;
}