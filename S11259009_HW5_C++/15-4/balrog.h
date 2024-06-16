//This is the head file of balrog.cpp.
//This is the interface of balrog.h.
#ifndef BALROG_H
#define BALROG_H
#include"demon.h"

class Balrog : public Demon {
public:
	Balrog();
	Balrog(int newStrength, int newHits);

	int getDamage() const override;
	string getSpecies() const override;
};

#endif