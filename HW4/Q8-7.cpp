/*
* Define a class named PrimeNumber stores a prime number.
* Overload operator++, -- with prefix and postfix version.
* Test the class with appropriate method.
*/
#include<iostream>
#include<cmath>

using namespace std;

class PrimeNumber {
public:
	// constructors
	PrimeNumber(int userEnter):prime(userEnter){}
	PrimeNumber():prime(1){}
	// get function
	int getPrime() const { return prime; }

	// operator ++, prefix and postfix
	PrimeNumber operator ++();
	PrimeNumber operator ++(int);
	// operator --, prefix and postfix
	PrimeNumber operator --();
	PrimeNumber operator --(int);

	// return true if the parameter number is a prime
	bool isPrime(int);
private:
	int prime;
};

// function to test PrimeNumber with appropriate methods
void testPrimeNumber();

int main() {

	testPrimeNumber();

	return 0;
}

// operator ++, prefix and postfix
PrimeNumber PrimeNumber::operator ++() {
	prime++;
	while (!isPrime(prime)) {
		prime++;
	}
	return PrimeNumber(prime);
}
PrimeNumber PrimeNumber::operator ++(int ignoreMe) {
	int temp = prime;
	prime++;
	while (!isPrime(prime)) {
		prime++;
	}
	return PrimeNumber(temp);
}

// operator --, prefix and postfix
PrimeNumber PrimeNumber::operator --() {
	prime--;
	while (!isPrime(prime)) {
		prime--;
	}
	return PrimeNumber(prime);
}
PrimeNumber PrimeNumber::operator --(int ignoreMe) {
	int temp = prime;
	prime--;
	while (!isPrime(prime)) {
		prime--;
	}
	return PrimeNumber(temp);
}

// determine if the number is a prime
bool PrimeNumber::isPrime(int number) {
	if (number <= 1) {
		return false;
	}

	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

void testPrimeNumber() {
	// test for default constructor
	PrimeNumber num1;
	cout << "Test default constructor: " << num1.getPrime() << endl;
	
	// test for user enter constructor
	int userNum;
	cout << "Enter a number for testing constructor: "; cin >> userNum;
	PrimeNumber num2(userNum);
	cout << "Test caller set constructor: " << num2.getPrime() << endl;
	
	// test ++
	cout << "\nTest ++: " << endl;
	PrimeNumber num3(29);
	cout << "num3 = " << num3.getPrime() << endl;
	// prefix version
	PrimeNumber num4 = num3++;
	cout << "num4 = num3++,  num4 = " << num4.getPrime() << ",  num3 = " << num3.getPrime() << endl;
	// postfix version
	PrimeNumber num5 = ++num3;
	cout << "num5 = ++num3,  num5 = " << num5.getPrime() << ",  num3 = " << num3.getPrime() << endl;

	// test --
	cout << "\nTest -- " << endl;
	PrimeNumber num6(8);
	cout << "num6 = " << num6.getPrime() << endl;
	// prefix version
	PrimeNumber num7 = num6--;
	cout << "num7 = num6--,  num7 = " << num7.getPrime() << ",  num6 = " << num6.getPrime() << endl;
	// postfix version
	PrimeNumber num8 = --num6;
	cout << "num8 = --num6,  num8 = " << num8.getPrime() << ",  num6 = " << num6.getPrime() << endl;
}