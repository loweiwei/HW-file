#include"elf.h"
#include<iostream>
#include<cstring>
using namespace std;

Elf::Elf() :Creature() {};

Elf::Elf(int newStrength, int newHit) :Creature(newStrength, newHit) {}

string Elf::getSpecies() {
    return "Elf";
}
int Elf::getDamage() {
    int damage = Creature::getDamage();
    if (rand() % 10 == 0) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << std::endl;
        damage *= 2;
    }
    return damage;
}