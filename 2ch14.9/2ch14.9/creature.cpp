#include"creature.h"
#include<iostream>
#include<cstring>
using namespace std;

string Creature::getSpecies()
{
    switch (type)
    {
    case 0: return "Human";
    case 1: return "Cyberdemon";
    case 2: return "Balrog";
    case 3: return "Elf";
    }
    return "Unknown";
}

Creature::Creature() :type(0), strength(10), hitpoints(10) {};

Creature::Creature(int newStrength, int newHit) : strength(newStrength), hitpoints(newHit) {}

int Creature::getstrength() { return strength; }

int Creature::gethitpoints() { return hitpoints; }

int Creature::getDamage() {
    int damage = (rand() % strength) + 1;
    cout << getSpecies() << "attacks for" << damage << "points.\n";
    return damage;
}

void Creature::setstrength(int newStrength) { strength = newStrength; }

void Creature::sethitpoints(int newHit) { hitpoints = newHit; }