#ifndef cyberdemon_h
#define cyberdemon_h
#include"demon.h"
#include<iostream>
#include<cstring>
using namespace std;

class Cyberdemon :public Demon {
public:
    Cyberdemon();
    Cyberdemon(int newStrength, int newHit);
    string getSpecies();
};
#endif

