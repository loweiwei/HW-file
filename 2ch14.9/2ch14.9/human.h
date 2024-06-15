#ifndef human_h
#define human_h
#include"creature.h"
#include<iostream>
#include<cstring>
using namespace std;

class Human :public Creature {
public:
    Human();
    Human(int newStrength, int newHit);
    string getSpecies();
};
#endif

