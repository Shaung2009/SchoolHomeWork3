#include"loadedDice.h"
#include<cstdlib>
using namespace std;

LoadedDice::LoadedDice() : Dice() {}
LoadedDice::LoadedDice(int numSides) : Dice(numSides) {}

// 50% chance that returns the largest number possible(i.e numSides)
int LoadedDice::rollDice() const {
	if ((rand() % 2) + 1 == 1) {
		return numSides;
	}
	else {
		return Dice::rollDice();
	}
}