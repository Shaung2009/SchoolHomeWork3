//This is the head file of demon.cpp.
//This is the interface of demon.h.
//This is primary to be a base class to be derived by some sort of demon.
#ifndef DEMON_H
#define DEMON_H

#include"creature.h"

class Demon : public Creature {
public:
	Demon();
	Demon(int newStrength, int newHit);

	int getDamage() const override;		// 5% +50 damage point
	string getSpecies() const override;	// Return "Demon"
};

#endif	