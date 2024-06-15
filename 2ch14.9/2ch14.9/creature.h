#ifndef creature_h
#define creature_h
using namespace std;
#include <iostream>
#include<cstring>


class Creature
{
private:
    int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf 
    int strength; // How much damage we can inflict
    int hitpoints; // How much damage we can sustain 
    string getSpecies(); // Returns type of species
public:
    Creature()  ; // Initialize to human, 10 strength, 10 hit points
    Creature(int newStrength, int newHit);// Initialize creature to new type, strength, hit points

    //Also add appropriate accessor and mutator functions for type, strength, and hit points
    //string gettype() { return getSpecies(); }
    //int gettype() { return type; }
    int getstrength();
    int gethitpoints();
    // Returns amount of damage this creature // inflicts in one round of combat
    int getDamage();
    //void settype(int newtype) { type = newtype; }
    void setstrength(int newStrength);
    void sethitpoints(int newHit);
};
#endif

