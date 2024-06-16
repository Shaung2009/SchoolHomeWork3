//This is the header file employee.h.
//This is the interface for the class Employee.
//This is primary intended to be used as a base class to derive
//classes for different kinds of employees
#ifndef EMPLOYEE_H
#define EMPLOYEE_Y

#include<string>
using namespace std;

class Employee {
public:
	Employee();
	Employee(const string& theName, const string& theSsn);
	void setName(const string& newName);
	void setSsn(const string& newNumber);
	void setNetPay(const double newNetPay);
	string getName() const;
	string getSsn() const;
	double getNetPay() const;

	void printCheck() const;
private:
	string name;
	string ssn;
	double netPay;
};

#endif