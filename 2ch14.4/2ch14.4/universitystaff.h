#ifndef universitystaff_h
#define universitystaff_h
#include <string>
#include<iostream>
using namespace std;

class UniversityStaff {
public:
    UniversityStaff();
    UniversityStaff(string theName);
    UniversityStaff(const UniversityStaff& theObject);
    string getName() const;
    UniversityStaff& operator=(const UniversityStaff& rtSide);
    friend istream& operator >>(istream& inStream, UniversityStaff& staffObject);
    friend ostream& operator <<(ostream& outStream, const UniversityStaff& staffObject);
private:
    string name;
};

#endif
