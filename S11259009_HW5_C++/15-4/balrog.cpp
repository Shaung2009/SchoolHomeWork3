#include"balrog.h"
#include<time.h>
#include<iostream>
using namespace std;
Balrog::Balrog() : Demon() {}
Balrog::Balrog(int newStrength, int newHits) : Demon(newStrength, newHits) {}


int Balrog::getDamage() const{
	// All creatures inflict damage, which is a random number up to their strength
	int damage = Demon::getDamage();

	//Balrogs are so fast they get to attack twice
	cout << "Balrog speed attack inflicts " << "additional damage points!" << endl;
	int damage2 = Demon::getDamage();

	return damage + damage2;
}

string Balrog::getSpecies() const {
	return "Balrog";
}