#include"elves.h"
#include<time.h>

Elves::Elves() : Creature() {}
Elves::Elves(int newStrength, int newHit) : Creature(newStrength, newHit) {}

int Elves::getDamage() const{
	int damage, damage2 = 0;
	// All creatures inflict damage, which is a random number up to their strength
	damage = rand() % (getStrength() - 1 + 1) + 1;
	cout << getSpecies() << " attack for " << damage << " points!" << endl;

	// Elves inflict double magical damage witth a 10% chance
	if (rand() % (100 - 1 + 1) + 1 <= 10) {
		damage2 = damage;
		cout << "Magical attack inflicts " << damage2
			<< " additional damage points!" << endl;
	}
	return damage + damage2;
}

string Elves::getSpecies() const {
	return "Elves";
}