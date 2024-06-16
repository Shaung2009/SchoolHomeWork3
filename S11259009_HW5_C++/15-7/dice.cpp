#include"dice.h"
#include<cstdlib>
using namespace std;

Dice::Dice() {
	numSides = 6;
//	srand(time(NULL));	//Seeds random number generator
}
Dice::Dice(int numSides) {
	this->numSides = numSides;
//	srand(time(NULL));
}
int Dice::rollDice() const{
	return (rand() % numSides) + 1;
}