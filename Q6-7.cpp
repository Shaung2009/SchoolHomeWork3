/* A test program creates output description and price of various pizza objects. */
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Pizza {
public:
	Pizza(string type, string size, int number);
	Pizza();

	string getPizzaType() const;
	string getPizzaSize() const;
	int getNumToppings() const;

	void outputDescription() const;	//output description of the pizza object
	double computePrice() const;	//return price (small($10), medium(14), large(17), and for each topping is ($2))
private:
	string pizzaType;		//deep dish, hand tossed, or pan
	string pizzaSize;		//small, medium, or large
	int numToppings;		//pepperoni or cheese
	void testData() const;	//test the enter format is right or not
};

int main() {
	cout << "Testing for class Pizza.\n\n";	//inform this is a test for the class Pizza

	Pizza aPizza;
	string type, size;
	int numPepperoni = 0, numCheese = 0, numToppings = 0;

	aPizza.outputDescription();		//output description

	cout << "Enter pizza type\n> ";
	getline(cin, type);				//useing getline to avoid blanks
	cout << "Enter pizza size\n> ";
	getline(cin, size);				//useing getline to avoid blanks
	cout << "Enter number of topping for pepperroni\n> ";
	cin >> numPepperoni;
	cout << "Enter number of topping for cheese\n> ";
	cin >> numCheese;

	numToppings = numPepperoni + numCheese;

	aPizza = Pizza(type, size, numToppings);

	cout << "the price of this pizza is $" << aPizza.computePrice() << endl;

	system("PAUSE");
	return 0;
}

/* Constructor. */
Pizza::Pizza(string type, string size, int number)
	:pizzaType(type), pizzaSize(size), numToppings(number) {
	testData();
}
/* Defalut constructor. */
Pizza::Pizza() :pizzaType("deep dish"), pizzaSize("small"), numToppings(0) {}

/* Accessers to private variables. */
string Pizza::getPizzaType() const { return pizzaType; }
string Pizza::getPizzaSize() const { return pizzaSize; }
int Pizza::getNumToppings() const { return numToppings; }

/* Output description the the user should know. */
void Pizza::outputDescription() const {
	cout << "Pizza types: deep dish, hand tossed, and pan." << endl;
	cout << "Pizza sizes: small, medium, and large." << endl;
	cout << "Topping types: pepperroni, and cheese." << endl;
	cout << "Small is $10, medium is $14, large is $17, \nas for the price of toppings is $2 per toppings.\n" << endl;
}
/* Compute the price according to the given rules. */
double Pizza::computePrice() const {
	int total = 0;
	if (pizzaSize == "small") {
		total += 10;
	}
	else if (pizzaSize == "medium") {
		total += 14;
	}
	else if (pizzaSize == "large") {
		total += 17;
	}
	else {
		cout << "Enter pizza size wrong!\n";
		exit(1);
	}

	total += numToppings * 2;

	return total;
}

/* If the enter format is not as expect, exit the program and tell the wrong part. */
void Pizza::testData() const{
	bool isRight = true;	//assume all enter format is right

	if (!(pizzaType == "deep dish" || pizzaType == "hand tossed" || pizzaType == "pan")) {
		cerr << "Enter format of pizza type is wrong!\n";
		isRight = false;
	}
	if (!(pizzaSize == "small" || pizzaSize == "medium" || pizzaSize == "large")) {
		cerr << "Enter format of pizza size is wrong!\n";
		isRight = false;
	}
	if (!(numToppings >= 0)) {
		cerr << "Enter format of nummber of pizza toppings is wrong!\n";
		isRight = false;
	}

	if (!isRight) {
		exit(1);		//exit the program if there's at least one error
	}
}