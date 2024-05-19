#include<iostream>
#include "Security.h"
#include "User.h"

using namespace std;

// Implementation of the Login method: uses the Security class for validation
bool User::Login(const string& username, const string& password) const{
	Security securityUser;
	// Returns true if the validate method returns 1 or 2 (user or administrator)
	if (securityUser.validate(username, password) == 1 ||
		securityUser.validate(username, password) == 2) return true;
}