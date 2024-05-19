#include<iostream>
#include "Security.h"

// Implementation of the validate method: checks the username and password
int Security::validate(const string& username, const string& password) {
	if ((username == "abbott") && (password == "monday")) return 1;		// User abbott
	if ((username == "costello") && (password == "tuesday")) return 2;	// Administrator costello
	return 0;
}