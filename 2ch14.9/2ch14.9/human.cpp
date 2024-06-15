#include<iostream>
#include<cstring>
#include"human.h"
using namespace std;

Human::Human() :Creature() {};
Human::Human(int newStrength, int newHit) :Creature(newStrength, newHit) {}
string Human::getSpecies() {
    return "Human";
}