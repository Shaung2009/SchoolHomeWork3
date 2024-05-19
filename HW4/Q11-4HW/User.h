#ifndef USER_H
#define USER_H

#include<iostream>

using namespace std;

// Definition of the User class, providing a Login method
class User{
public:
	// Login method: verifies if the user is a user or an administrator
	bool Login(const string& username, const string& password) const;
};
#endif