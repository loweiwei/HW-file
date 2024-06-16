#include <string>
#include <cstdlib>
#include <iostream>
#include "universitystaff.h"
using namespace std;

UniversityStaff::UniversityStaff() :name("not name yet") {}

UniversityStaff::UniversityStaff(string theName) :name(theName) {}

UniversityStaff::UniversityStaff(const UniversityStaff& theObject) :name(theObject.getName()) {}

string UniversityStaff::getName() const { return name; }

UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtSide)
{
    name = rtSide.getName();
    return *this;
}

istream& operator>>(istream& inStream, UniversityStaff& staffObject)
{

    inStream >> staffObject.name;
    return inStream;
}

ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject)
{
    outStream << "the UniversityStaff's name is:" << staffObject.getName() << endl;
    return outStream;
}