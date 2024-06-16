#include<iostream>
#include<string>
#include"salariedEmployee.h"

using namespace std;

class Administrator : public SalariedEmployee {
public:
    void setTitle(const string& theTitle);
    void setArea(const string& theArea);
    void setSupervisor(const string& newNameSupervisor);

    string getTitle() const;
    string getArea() const;
    string getSupervisor() const;

    void setAdministratorInfo();    // Reading in an administrator's data from the keyboard
    void print() const;             // Output the object's data to the screen
    void printCheck();        // Print check
private:
    string title; //Administrator's title (such as Director or Vice President)
    string area; //the company of responsibility (such as Production, Accounting, or Personnel)
    string nameSupervisor; //The name of the Administrator's immediate supervisor
protected:
    double salaryAnn; //Administrator's annual salary
};

int main() {
    Administrator Alan;

    Alan.setAdministratorInfo();
    Alan.print();
    Alan.printCheck();

    return 0;
}

void Administrator::setTitle(const string& theTitle) {
    title = theTitle;
}

void Administrator::setArea(const string& theArea) {
    area = theArea;
}

void Administrator::setSupervisor(const string& newNameSupervisor) {
    nameSupervisor = newNameSupervisor;
}

string Administrator::getTitle() const {
    return title;
}

string Administrator::getArea() const {
    return area;
}

string Administrator::getSupervisor() const {
    return nameSupervisor;
}

void Administrator::setAdministratorInfo() {
    cout << "Enter title of the administrator: ";
    getline(cin, title);
    cout << "Enter area of the company of responsibility: ";
    getline(cin, area);
    cout << "Enter supervisor of the administrator: ";
    getline(cin, nameSupervisor);
    cout << "Enter annually salary: ";
    cin >> salaryAnn;
    cout << "Enter name: ";
    string newName;
    cin.ignore(); // Ignore the newline character left in the buffer
    getline(cin, newName);
    setName(newName);
    cout << "Enter SSN: ";
    string newSsn;
    getline(cin, newSsn);
    setSsn(newSsn);
    cout << "Enter net pay: ";
    double newNetPay;
    cin >> newNetPay;
    setNetPay(newNetPay);
    cout << "Enter salary: ";
    double newSalary;
    cin >> newSalary;
    setSalary(newSalary);
}

void Administrator::print() const {
    cout << "Administrator's Information:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "SSN: " << getSsn() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Supervisor: " << getSupervisor() << endl;
    cout << "Net Pay: " << getNetPay() << endl;
    cout << "Salary: " << getSalary() << endl;
}

void Administrator::printCheck() {
    setNetPay(getSalary());
    cout << "\n__________________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getNetPay() << " Dollars\n";
    cout << "____________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << getSsn() << endl;
    cout << "Administrator. Regular Pay: " << getSalary() << endl;
    cout << "____________________________________________\n";
}
