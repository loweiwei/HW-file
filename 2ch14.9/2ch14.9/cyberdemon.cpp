#include"cyberdemon.h"
#include<iostream>
#include<cstring>
using namespace std;

Cyberdemon::Cyberdemon() :Demon() {};

Cyberdemon::Cyberdemon(int newStrength, int newHit) :Demon(newStrength, newHit) {}

string Cyberdemon::getSpecies() {
    return "Cyberdemon";
}