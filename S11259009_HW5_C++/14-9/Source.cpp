#include <iostream>
#include <cstdlib>
#include <ctime>
#include "human.h"
#include "elves.h"
#include "cyberdemon.h"
#include "balrog.h"

const int iniDamage = 10;
const int iniHitpoints = 50;

void battle(Creature& c1, Creature& c2) {
    int damage1, damage2;
    int health1 = c1.getHitpoints();
    int health2 = c2.getHitpoints();

    int i = 1;

    cout << "Battle between " << c1.getSpecies() << " and " << c2.getSpecies() << " : " << endl;
    while (c1.getHitpoints() > 0 && c2.getHitpoints() > 0) {
        cout << "Round " << i++ << endl;
        damage1 = c1.getDamage();
        damage2 = c2.getDamage();
        c2.setHitpoints(c2.getHitpoints() - damage1);
        c1.setHitpoints(c1.getHitpoints() - damage2);
        
        cout << "Remain hitpoints: " << endl;
        cout << c1.getSpecies() << ": " << c1.getHitpoints() << endl;
        cout << c2.getSpecies() << ": " << c2.getHitpoints() << endl;

        if (c1.getHitpoints() <= 0 && c2.getHitpoints() <= 0) {
            cout << "DRAW!! both creature's hitpoints have droped below 0." << endl;
        }
        else if (c1.getHitpoints() <= 0) {
            cout << c2.getSpecies() << " WON!!" << endl;
        }
        else if(c2.getHitpoints() <= 0){
            cout << c1.getSpecies() << " WON!!" << endl;
        }
    }
    cout << "________________________________________________________" << endl;

    //Initialize both creature's hitpoints
    c1.setHitpoints(health1);
    c2.setHitpoints(health2);
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Random seeds for rand()

    Human h1(iniDamage, iniHitpoints);
    Elves e1(iniDamage, iniHitpoints);
    Cyberdemon cd1(iniDamage, iniHitpoints);
    Balrog b1(iniDamage, iniHitpoints);

    cout << "All creature has a initial damage of 20 and hitpoints of 30.\n" << endl;

    //Human vs Elf
    battle(h1, e1);
    //Cyberdemon vs balrog
    battle(cd1, b1);
    //Human vs Cyberdemon
    battle(h1, cd1);
    //Elf vs balrog
    battle(e1, b1);

    return 0;
}