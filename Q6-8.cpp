/* Tests of all function in the class Money with two different objects. */
#include<iostream>
using namespace std;

class Money {
public:
	Money();

	void setNumDollars(int dollars);
	void setNumCents(int cents);

	int getNumDollars() const;
	int getNumCents() const;

	double monetaryAmount() const;
private:
	int numDollars;
	int numCents;
};

int main() {
	cout << "Testing for class Money.(twice)\n\n";	//informing this is a test for class Money

	Money persons[2];
	int dollars, cents;
	
	//for-loop to execute twice(two different Money objects)
	for (int i = 0; i < 2; i++) {
		cout << "Enter number of dollars\n> ";
		cin >> dollars;
		persons[i].setNumDollars(dollars);
		cout << "Enter number of cents\n> ";
		cin >> cents;
		persons[i].setNumCents(cents);

		cout << "The monetary amount is $" << persons[i].monetaryAmount() << endl;
	}

	return 0;
}

/* Default constructor. */
Money::Money() :numDollars(0), numCents(0) {}

/* Mutators to set numDollars and numCents. */
void Money::setNumDollars(int dollars) { numDollars = dollars; }
void Money::setNumCents(int cents) { numCents = cents; }

/* Accessors to get numDollars and numCents. */
int Money::getNumDollars() const { return numDollars; }
int Money::getNumCents() const { return numCents; }

/* Return the monerary amount(dollars + cents). */
double Money::monetaryAmount() const { return numDollars + numCents * 0.01; }