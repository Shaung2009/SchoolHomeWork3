#ifndef SECURITY_H
#define SECURITY_H

#include<iostream>

using namespace std;

// Definition of the Security class, providing a static method validate for user authentication
class Security {
public:
	// validate method: checks if the username and password match and returns the validation result
	static int validate(const string& username, const string& password);
};
#endif