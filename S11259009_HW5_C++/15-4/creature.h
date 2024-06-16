//This is the head file of creature.cpp.
//This is the interface of creature.h.
//This is primary to be a base class to be derived by some sort of creatures.
#ifndef CREATURE_H
#define CREATURE_H

#include<iostream>
using namespace std;

class Creature {
public:
	// Initialize to 10 strength, 10 hit points
	Creature();
	
	// Initialize creature to new strength, hit points
	Creature(int newStrength, int newHit);

	// Mutators
	void setStrength(const int newStrength);
	void setHitpoints(const int newHitpoints);
	 
	// Accessors
	int getStrength() const;
	int getHitpoints() const;

	// Returns amount of damage this creature inflicts in one round of combat
	virtual int getDamage() const;

	virtual string getSpecies() const = 0;	// Returns type of species

private:
	int strength;	// How much damage we can inflict
	int hitpoints;	// How much damage we can sustain
};

#endif