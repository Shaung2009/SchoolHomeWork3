/* Testing for class Weight. */
#include<iostream>
#include<cstdlib>
using namespace std;

class Weight {
public:
	void setWeightPounds(double& weight);
	void setWeightKilograms(double& weight);
	void setWeightOunces(double& weight);

	double getWeightInPounds() const;
	double getWeightInKilograms() const;
	double getWeightInOunces() const;
private:
	double weightInPounds;
};

int main() {
	cout << "Testing for class Weight\n\n";
	
	Weight testWeight;
	double weight;
	char unitTransform;

	cout << "Enter weight in pounds\n> ";	//Enter weight in a specified weight scale.
	cin >> weight;
	testWeight.setWeightPounds(weight);

	cout << "Weight in pounds: " << testWeight.getWeightInPounds() << endl;
	cout << "Weight in kilograms: " << testWeight.getWeightInKilograms() << endl;
	cout << "Weight in ounces: " << testWeight.getWeightInOunces() << endl;

	system("PAUSE");
	return 0;
}

/* Set pounds to the following unit. */
void Weight::setWeightPounds(double& weight) { weightInPounds = weight; }
void Weight::setWeightKilograms(double& weight) { weightInPounds = weight / 2.21; }
void Weight::setWeightOunces(double& weight) { weightInPounds = weight * 16; }

/* Return weight in pounds to the following unit. */
double Weight::getWeightInPounds() const { return weightInPounds; }
double Weight::getWeightInKilograms() const { return weightInPounds / 2.21; }
double Weight::getWeightInOunces() const { return weightInPounds * 16; }