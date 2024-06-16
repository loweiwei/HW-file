#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
using namespace std;

class Creature
{
private:
    int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf 
    int strength; // How much damage we can inflict
    int hitpoints; // How much damage we can sustain 
    virtual string getSpecies(); // Returns type of species
public:
    Creature() :type(0), strength(10), hitpoints(10) {}; // Initialize to human, 10 strength, 10 hit points
    Creature(int newStrength, int newHit) : strength(newStrength), hitpoints(newHit) {}// Initialize creature to new type, strength, hit points

    //Also add appropriate accessor and mutator functions for type, strength, and hit points
    
    int getstrength() { return strength; }
    int gethitpoints() { return hitpoints; }
    void setstrength(int newStrength) { strength = newStrength; }
    void sethitpoints(int newHit) { hitpoints = newHit; }

    // Returns amount of damage this creature // inflicts in one round of combat
    virtual int getDamage() {
        int damage = (rand() % strength) + 1;
        cout << getSpecies() << "attacks for" << damage << "points.\n";
        return damage;
    }

    virtual string getSpecies() = 0;

};
//Here is an implementation of the getSpecies() function:
/*string Creature::getSpecies()
{
    switch (type)
    {
    case 0: return "Human";
    case 1: return "Cyberdemon";
    case 2: return "Balrog";
    case 3: return "Elf";
    }
    return "Unknown";
}*/

class Human :public Creature {
public:
    Human() :Creature() {};
    Human(int newStrength, int newHit) :Creature(newStrength, newHit) {}
    string getSpecies() override {
        return "Human";
    }
};

class Elf :public Creature {
public:
    Elf() :Creature() {};
    Elf(int newStrength, int newHit) :Creature(newStrength, newHit) {}
    string getSpecies() override {
        return "Elf";
    }
    int getDamage() override {
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
    int getDamage() override {
        int damage = Creature::getDamage();
        if (rand() % 100 < 5) {
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
    string getSpecies() override {
        return "Cyberdemon";
    }
};

class Balrog :public Demon {
public:
    Balrog() :Demon() {};
    Balrog(int newStrength, int newHit) :Demon(newStrength, newHit) {}
    string getSpecies() override {
        return "Balrog";
    }
    int getDamage() override {
        int damage = Demon::getDamage();
        int damage2 = (rand() % getstrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << std::endl;
        damage += damage2;
        return damage;
    }
};

void battlearea(Creature& creature1, Creature& creature2)
{
    while (creature1.gethitpoints() > 0 && creature2.gethitpoints() > 0) {
        int damage1 = creature1.getDamage();
        int damage2 = creature2.getDamage();

        creature1.sethitpoints(creature1.gethitpoints() - damage2);
        creature2.sethitpoints(creature2.gethitpoints() - damage1);

        cout << creature1.getSpecies() << " hit points: " << creature1.gethitpoints() << endl;
        cout << creature2.getSpecies() << " hit points: " << creature2.gethitpoints() << endl;

        if (creature1.gethitpoints() <= 0 && creature2.gethitpoints() <= 0) {
            cout << "The battle is a tie!" << endl;
            return;
        }
        else if (creature1.gethitpoints() <= 0) {
            cout << creature2.getSpecies() << " wins the battle!" << endl;
            return;
        }
        else if (creature2.gethitpoints() <= 0) {
            cout << creature1.getSpecies() << " wins the battle!" << endl;
            return;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    Human human(30, 100);
    Elf elf(40, 100);
    Cyberdemon cyberdemon(50, 100);
    Balrog balrog(60, 100);


    battlearea(human, elf);
    battlearea(cyberdemon, balrog);
    battlearea(elf, balrog);

    return 0;
}