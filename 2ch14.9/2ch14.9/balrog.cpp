#include"balrog.h"
#include<iostream>
#include<cstring>
using namespace std;

Balrog::Balrog() :Demon() {};

Balrog::Balrog(int newStrength, int newHit) :Demon(newStrength, newHit) {}

string Balrog::getSpecies() {
    return "Balrog";
}

int Balrog::getDamage() {
    int damage = Demon::getDamage();
    int damage2 = (rand() % getstrength()) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << std::endl;
    damage += damage2;
    return damage;
}