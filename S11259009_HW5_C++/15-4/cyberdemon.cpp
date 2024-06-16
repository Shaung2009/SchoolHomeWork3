#include"cyberdemon.h"
#include<time.h>

Cyberdemon::Cyberdemon() : Demon() {}
Cyberdemon::Cyberdemon(int newStrength, int newHits) : Demon(newStrength, newHits) {}

string Cyberdemon::getSpecies() const {
	return "Cyberdemon";
}