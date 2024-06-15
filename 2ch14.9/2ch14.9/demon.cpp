#include"demon.h"
#include<iostream>
#include<cstring>
using namespace std;

Demon::Demon() :Creature() {};
Demon::Demon(int newStrength, int newHit) :Creature(newStrength, newHit) {}
/*tring getSpecies() {
    return "Demon";
}*/
int Demon::getDamage() {
    int damage = Creature::getDamage();
    if (rand() % 100 < 5) {
        cout << "Demonic attack inflicts 50 additional damage points!" << std::endl;
        damage += 50;
    }
    return damage;
}