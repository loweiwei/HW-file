#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include"creature.h"
#include"human.h"
#include"elf.h"
#include"demon.h"
#include"cyberdemon.h"
#include"balrog.h"
using namespace std;

#if 0

class Creature
{
private:
    int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf 
    int strength; // How much damage we can inflict
    int hitpoints; // How much damage we can sustain 
    string getSpecies(); // Returns type of species
public:
    Creature() :type(0), strength(10), hitpoints(10) {}; // Initialize to human, 10 strength, 10 hit points
    Creature(int newStrength, int newHit): strength(newStrength), hitpoints(newHit) {}// Initialize creature to new type, strength, hit points

    //Also add appropriate accessor and mutator functions for type, strength, and hit points
    //string gettype() { return getSpecies(); }
    //int gettype() { return type; }
    int getstrength() { return strength; }
    int gethitpoints() { return hitpoints; }
    // Returns amount of damage this creature // inflicts in one round of combat
    int getDamage() {
        int damage = (rand() % strength) + 1;
        cout << getSpecies() << "attacks for" << damage << "points.\n";
        return damage;
    } 

    //void settype(int newtype) { type = newtype; }
    void setstrength(int newStrength) { strength = newStrength; }
    void sethitpoints(int newHit) { hitpoints = newHit; }
    
};
//Here is an implementation of the getSpecies() function:
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

class Human :public Creature {
public:
    Human() :Creature() {};
    Human(int newStrength, int newHit) :Creature(newStrength, newHit){}
    string getSpecies() {
        return "Human";
    }
};

class Elf :public Creature {
public:
    Elf() :Creature() {};
    Elf(int newStrength, int newHit) :Creature(newStrength, newHit) {}
    string getSpecies() {
        return "Elf";
    }
    int getDamage() {
        int damage = Creature::getDamage();
        if (rand() % 10 == 0) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << std::endl;
            damage *= 2;
        }
        return damage;
    }
};

class Demon :public Creature {
public:
    Demon() :Creature() {};
    Demon(int newStrength, int newHit) :Creature(newStrength, newHit) {}
    /*tring getSpecies() {
        return "Demon";
    }*/
    int getDamage() {
        int damage = Creature::getDamage();
        if (rand() % 100 <5) {
            cout << "Demonic attack inflicts 50 additional damage points!" << std::endl;
            damage += 50;
        }
        return damage;
    }
};

class Cyberdemon :public Demon {
public:
    Cyberdemon() :Demon() {};
    Cyberdemon(int newStrength, int newHit) :Demon(newStrength, newHit) {}
    string getSpecies() {
        return "Cyberdemon";
    }
};

class Balrog :public Demon {
public:
    Balrog() :Demon() {};
    Balrog(int newStrength, int newHit) :Demon(newStrength, newHit) {}
    string getSpecies() {
        return "Balrog";
    }
    int getDamage() {
        int damage = Demon::getDamage();
        int damage2 = (rand() % getstrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << std::endl;
        damage += damage2;
        return damage;
    }
};
#endif // 0


int main() {
    srand(static_cast<unsigned>(time(0)));

    Human human(30, 100);
    Elf elf(40, 100);
    Cyberdemon cyberdemon(50, 100);
    Balrog balrog(60, 100);

    cout << "\nHuman damage: " << human.getDamage() << std::endl;
    cout << "\nElf damage: " << elf.getDamage() << std::endl;
    cout << "\nCyberdemon damage: " << cyberdemon.getDamage() << std::endl;
    cout << "\nBalrog damage: " << balrog.getDamage() << std::endl;

    return 0;
}