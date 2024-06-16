//This is the definition for class Creature.
//This is the content file creature.cpp
#include"creature.h"

using namespace std;

// Initialize to 10 strength, 10 hit points
Creature::Creature()
	:strength(10), hitpoints(10) { /* Intentionally empty... */
}

// Initialize creature to new type, strength, hit points
Creature::Creature(int newStrength, int newHit)
	:strength(newStrength), hitpoints(newHit) { /* Intentionally empty... */ }

// Mutators

void Creature::setStrength(const int newStrength) {
	strength = newStrength;
}
void Creature::setHitpoints(const int newHitpoints) {
	hitpoints = newHitpoints;
}

// Accessors
int Creature::getStrength() const {
	return strength;
}
int Creature::getHitpoints() const {
	return hitpoints;
}

// Returns amount of damage this creature inflicts in one round of combat
int Creature::getDamage() const {
	int damage;

	// All creatures inflict damage, which is a random number up to their strength
	damage = rand() % (strength - 1 + 1) + 1;
	cout << getSpecies() << " attack for " << damage << " points!" << endl;

	return damage;
}