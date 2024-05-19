 /* 
 * Create class Complex to store real, imaginary numbers.
 * The class should has overloading operators: +, -, *, ==, <<, >>.
 * Testing the class the main.
 */
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class Complex {
public:
	// Constructors
	Complex(double, double);	// set to any number
	Complex(double);			// realPart + 0 * i
	Complex();					// initiallize to 0 + 0 * i
	
	// Get functions
	double getReal() const;
	double getImaginary() const;
private:
	// Overloading operators
	friend bool operator ==(const Complex& complex1, const Complex& complex2);
	friend const Complex operator +(const Complex& complex1, const Complex& complex2);
	friend const Complex operator -(const Complex& complex1, const Complex& complex2);
	friend const Complex operator *(const Complex& complex1, const Complex& complex2);
	friend istream& operator >>(istream& inputStream, Complex& complex);
	friend ostream& operator <<(ostream& outputStream, const Complex& complex);

	// Complex number
	double real;		// a + b * i
	double imaginary;	
};

// define a const i as follow in the interface file
const Complex i(0, 1);

// test function in main to test class Complex work properly
void testComplex();

int main() {

	testComplex();

	return 0;
}

/* Define constructors and get functors. */
Complex::Complex(double realValue, double imaginaryValue) :real(realValue), imaginary(imaginaryValue) {}
Complex::Complex(double realValue):real(realValue), imaginary(0) {}
Complex::Complex(): real(0), imaginary(0) {}
double Complex::getReal() const{ return real; }
double Complex::getImaginary() const{ return imaginary; }

/* Define overloading operators. */
bool operator ==(const Complex& complex1, const Complex& complex2) {
	return((complex1.getReal() == complex2.getReal()) && (complex1.getImaginary() == complex2.getImaginary()));
}

const Complex operator +(const Complex& complex1, const Complex& complex2) {
	double finalReal, finalImaginary;
	finalReal = complex1.getReal() + complex2.getReal();
	finalImaginary = complex1.getImaginary() + complex2.getImaginary();

	return Complex(finalReal, finalImaginary);
}

const Complex operator -(const Complex& complex1, const Complex& complex2) {
	double finalReal, finalImaginary;
	finalReal = complex1.getReal() - complex2.getReal();
	finalImaginary = complex1.getImaginary() - complex2.getImaginary();

	return Complex(finalReal, finalImaginary);
}

const Complex operator *(const Complex& complex1, const Complex& complex2) {
	double finalReal, finalImaginary;
	finalReal = complex1.getReal() * complex2.getReal() - complex1.getImaginary() * complex2.getImaginary();
	finalImaginary = complex1.getReal() * complex2.getImaginary() + complex1.getImaginary() * complex2.getReal();

	return Complex(finalReal, finalImaginary);
}

istream& operator >>(istream& inputStream, Complex& complex) {
	char sign, i;

	inputStream >> complex.real >> sign;
	if (sign == '+' || sign == '-') {
		inputStream >> complex.imaginary >> i;
		if (sign == '-') {
			complex.imaginary *= -1;
		}
	}
	else {
		cout << "No sign (+, -) detected!\n";
		exit(1);
	}
	if (i != 'i') {
		cout << "No i detected!\n";
		exit(1);
	}
}

ostream& operator <<(ostream& outputStream, const Complex& complex) {
	if (complex.getImaginary() >= 0) {
		outputStream << complex.getReal() << " + " << complex.getImaginary() << "i\n";
	}
	else {
		outputStream << complex.getReal() << complex.getImaginary() << "i\n";
	}
	return outputStream;
}

void testComplex() {
	/* Testing the constructors. */
	Complex complex1(5, -3), complex2(-2), complex3, complex4, complex5;

	cout << "Constructor with real and imaginary: " << complex1 << endl;

	cout << "Constructor with real: " << complex2 << endl;

	cout << "Constructor with default set: " << complex3 << endl;

	/* Testing the overloading operators. */
	complex4 = complex1 + complex2;
	cout << "Adding complex1 and complex2: " << complex4.getReal() << " " << complex4.getImaginary() << endl;
	complex4 = complex1 - complex2;
	cout << "Substracting complex1 and coplex2: " << complex4.getReal() << " " << complex4.getImaginary() << endl;
	complex4 = complex1 *complex2;
	cout << "Multiplying complex1 and coplex2: " << complex4.getReal() << " " << complex4.getImaginary() << endl;

	cout << "Display complexes with cout: \n" << complex1 << endl << complex2 << endl << complex3 << endl << complex4 << endl;
	cout << endl << Complex(10, -10);

	cout << "\nEnter a complex number: ";
	cin >> complex5;

	cout << "\nYou entered: " << complex5 << endl;

	cout << "\nThis is i: " << i << endl;

	/* Testing operator == */
	if (complex5 == complex5)
	{
		cout << "\nThis prints if the two are equal and " << complex5 << " is equal to " << complex5 << endl;
	}
}