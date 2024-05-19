#include<iostream>
#include "Security.h"
#include "Adminstrator.h"

using namespace std;

// Implementation of the Login method: uses the Security class for validation
bool Administrator::Login(const string& username, const string& password) const{
	Security securityAd;
	// Only returns true if the validate method returns 2 (administrator)
	if (securityAd.validate(username, password) == 2) return true;
}