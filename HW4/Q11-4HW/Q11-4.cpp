#include<iostream>
#include<string>
#include "Security.h"
#include "Adminstrator.h"
#include "User.h"

using namespace std;

// Function declaration
void testLogin();

int main() {
	
	// Execute login test
	testLogin();

	return 0;
}

void testLogin() {
	Administrator testA;
	User testU;
	string username, password;

	// test Login of User
	cout << "Test Login in User:\n";
	cout << "Enter username: "; getline(cin, username);
	cout << "Enter password: "; getline(cin, password);
	if (testU.Login(username, password)) {
		cout << "Validate for user!\n";				// Validation successful
	}
	else {
		cout << "User validate fail.\n";			// Validation failed
	}

	// test Login of Adminstrator
	cout << "\nTest Login in Adminstrator:\n";
	cout << "Enter username: "; getline(cin, username);
	cout << "Enter password: "; getline(cin, password);
	if (testA.Login(username, password)) {
		cout << "Validate for administrator!\n";	// Validation successful
	}
	else {
		cout << "Administrator validate fail.\n";	// Validation failed
	}
	cout << "\nDone test.\n";
}