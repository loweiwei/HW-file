#ifndef balrog_h
#define balrog_h
#include"demon.h"
#include<iostream>
#include<cstring>
using namespace std;

class Balrog :public Demon {
public:
    Balrog();
    Balrog(int newStrength, int newHit);
    string getSpecies();
    int getDamage();
};

#endif


