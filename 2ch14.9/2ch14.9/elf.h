#ifndef elf_h
#define elf_h
#include"creature.h"
#include<iostream>
#include<cstring>
using namespace std;

class Elf :public Creature {
public:
    Elf();
    Elf(int newStrength, int newHit);
    string getSpecies();
    int getDamage();
};


#endif

