#ifndef demon_h
#define demon_h
#include"creature.h"
#include<iostream>
#include<cstring>
using namespace std;

class Demon :public Creature {
public:
    Demon();
    Demon(int newStrength, int newHit);
    /*tring getSpecies() {
        return "Demon";
    }*/
    int getDamage();
};
#endif

