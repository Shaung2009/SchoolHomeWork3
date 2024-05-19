/*
* Define a class MyInteger stores an integer.
* With the help of overload operator [].
* For index i, return the dight in position i.
* i = 0 is the least-significant digit.
* If no such digit exist, then -1 should be returned.
*/

#include<iostream>
#include<string>

using namespace std;

class Integer {
public:
	//set functions
	void setInteger(int number) { integer = number; }
	//get functions
	int getInteger() const { return integer; }
	// overload []
	int operator[](int index);	// three dight number
private:
	// variable store integer
	int integer;
};

// test class Integer
void testInteger();

int main() {

	testInteger();

	return 0;
}

// operator []
int Integer::operator[](int index) {
	// trasform integer to string
	string str = to_string(integer);
	// reverse the string so that i could match the digit of the number
	reverse(str.begin(), str.end());

	if (index < 0 || index >= str.length()) {	// if not match
		return -1;
	}
	else {										// if in the range. Return the ASCII value(minus by '0')
		return str[index] - '0';
	}
}

// test class Integer
void testInteger() {
	Integer a;
	a.setInteger(1234);
	for (int i = 0; i <= 4; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}