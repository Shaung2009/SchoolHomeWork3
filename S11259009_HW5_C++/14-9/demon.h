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