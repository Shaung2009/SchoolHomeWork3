#include<iostream>
#include<string>
#include"salariedEmployee.h"

using namespace std;

SalariedEmployee::SalariedEmployee()
	:Employee(), salary(0){}
SalariedEmployee::SalariedEmployee(const string& theName, const string& theSsn, const double theWeeklySalary)
	:Employee(theName, theSsn), salary(theWeeklySalary){}
void SalariedEmployee::setSalary(double newSalary) {
	salary = newSalary;
}
double SalariedEmployee::getSalary() const { return salary; }

void SalariedEmployee::printCheck() {
	setNetPay(salary);
	cout << "\n__________________________________________\n";
	cout << "Pay to the order of " << getName() << endl;
	cout << "The sum of " << getNetPay() << "Dollars\n";
	cout << "____________________________________________\n";
	cout << "Check Stub NOT NEGOTIABLE \n";
	cout << "Employee Number: " << getSsn() << endl;
	cout << "Salaried Employee. Regular Pay: " << salary << endl;
	cout << "________________________________________________________________\n";
}