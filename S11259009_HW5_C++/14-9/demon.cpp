#include"demon.h"
#include<time.h>

using namespace std;

Demon::Demon() : Creature() {}
Demon::Demon(int newStrength, int newHit) : Creature(newStrength, newHit) {}

int Demon::getDamage() const{
	int damage;
	// All creatures inflict damage, which is a random number up to their strength
	damage = rand() % (getStrength() - 1 + 1) + 1;
	cout << getSpecies() << " attack for " << damage << " points!" << endl;

	// Demons can inflict damage of 50 with 5% chance
	if ((rand() % (100 - 1 + 1) + 1) <= 5) {
		damage += 50;
		cout << "Demonic attack inflicts 50 "
			<< " additional damage points!" << endl;
	}
	return damage;
}

string Demon::getSpecies() const {
	return "Demon";
}