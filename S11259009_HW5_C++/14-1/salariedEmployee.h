//This is the header file of salariedEmployee.h
//This is the interface for the class salariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include<string>
#include"employee.h"

using namespace std;

class SalariedEmployee: public Employee {
public:
	SalariedEmployee();
	SalariedEmployee(const string& theName, const string& theSsn, const double theWeeklySalary);
	void setSalary(double newSalary);
	double getSalary() const;

	void printCheck();
private:
	double salary;//weekly
};


#endif