#include<iostream>
#include<ctime>
#include"dice.h"
#include"loadedDice.h"

using namespace std;

// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2);

int main() {
	srand(time(NULL));
	// Executes rollTwoDice 10 times to test Dice
	/*
	int sum = 0, totalSum = 0;
	Dice dice1(4), dice2(6);
	cout << "Dice with 4 and 6 sides: " << endl;
	for (int i = 0; i < 10; i++) {
		sum = rollTwoDice(dice1, dice2);
		totalSum += sum;

		cout << i + 1 <<" : " << "sum = " << sum << endl;
	}
	cout << "Total sum = " << totalSum << endl;
	*/

	// Repalcing Dice to LoadedDice to test LoadedDice
	int sum = 0, totalSum = 0;
	LoadedDice dice1(4), dice2(6);
	cout << "Dice with 4 and 6 sides: " << endl;
	for (int i = 0; i < 10; i++) {
		sum = rollTwoDice(dice1, dice2);
		totalSum += sum;

		cout << i + 1 << " : " << "sum = " << sum << endl;
	}
	cout << "Total sum = " << totalSum << endl;

	return 0;
}

int rollTwoDice(const Dice& die1, const Dice& die2) {
	return die1.rollDice() + die2.rollDice();
}