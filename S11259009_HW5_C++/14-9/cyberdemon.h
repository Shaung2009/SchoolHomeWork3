#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include"demon.h"

class Cyberdemon : public Demon {
public:
	Cyberdemon();
	Cyberdemon(int newStrength, int newHits);

	string getSpecies() const override;
};

#endif