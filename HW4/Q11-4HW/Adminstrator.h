#ifndef ADMINSTRATOR_H
#define AMDINSTRATOR_H

#include<iostream>

using namespace std;

// Definition of the Administrator class, providing a Login method
class Administrator {
public:
	// Login method: verifies if the user is an administrator
	bool Login(const string& username, const string& password) const;
};
#endif