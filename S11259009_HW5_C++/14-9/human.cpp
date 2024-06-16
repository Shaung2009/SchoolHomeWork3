#include"human.h"

Human::Human() : Creature() {}
Human::Human(int newStrength, int newHit) : Creature(newStrength, newHit) {}

string Human::getSpecies() const {
	return "Human";
}