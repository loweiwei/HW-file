#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//constructor
Student::Student() :universityName(""), registrationnumber(0), proctor() {}
Student::Student(const string& uniname, int regnumebr, const UniversityStaff& proctorstaff) : universityName(uniname), registrationnumber(regnumebr), proctor(proctorstaff) {}
Student::Student(const Student& other) : universityName(other.universityName), registrationnumber(other.registrationnumber), proctor(other.proctor) {}

//accessor
string Student::getuniversityName()const { return universityName; }
int Student::getregistrationnumber()const { return registrationnumber; }
UniversityStaff Student::getproctor()const { return proctor; }

void Student::setuniversityName(const string& uniname) { universityName = uniname; }
void Student::setregistrationnumber(const int& regnumber) { registrationnumber = regnumber; }
void Student::setproctor(const UniversityStaff& proctorstaff) { proctor = proctorstaff; }

//overloading operator
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        universityName = other.universityName;
        registrationnumber = other.registrationnumber;
        proctor = other.proctor;
    }
    return *this;
}