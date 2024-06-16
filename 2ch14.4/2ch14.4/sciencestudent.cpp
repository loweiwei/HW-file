#include<iostream>
#include<cstring>
#include"sciencestudent.h"
using namespace std;

//constructor
sciencestudent::sciencestudent() :sciencediscipline(""), courselevel("") {}
sciencestudent::sciencestudent(const string& uniname, int regnumebr, const UniversityStaff& proctorstaff, const  string& scdiscipline, const string& level) :
    Student(uniname, regnumebr, proctorstaff), sciencediscipline(scdiscipline), courselevel(level) {}
sciencestudent::sciencestudent(const sciencestudent& other) : Student(other), sciencediscipline(other.sciencediscipline), courselevel(other.courselevel) {}

//accessor
string sciencestudent::getsciencediscipline() { return sciencediscipline; }
string sciencestudent::getcourselevel() { return courselevel; }
void sciencestudent::setsciencediscipline(string scdiscipline) { sciencediscipline = scdiscipline; }
void sciencestudent::setcourselevel(string level) { courselevel = level; }

//overloading operator
sciencestudent& sciencestudent::operator =(const sciencestudent& other)
{
    if (this != &other) {
        Student::operator =(other);
        sciencediscipline = other.sciencediscipline;
        courselevel = other.courselevel;
    }
    return *this;
}
