#ifndef student_h
#define student_h
#include <string>
#include "universitystaff.h"
using namespace std;

class Student
{
protected:
    string universityName;
    int registrationnumber;
    UniversityStaff proctor;
public:
    //constructor
    Student();
    Student(const string& uniname, int regnumebr, const UniversityStaff& proctorstaff);
    Student(const Student& other);

    //accessor
    string getuniversityName()const;
    int getregistrationnumber()const;
    UniversityStaff getproctor()const;

    void setuniversityName(const string& uniname);
    void setregistrationnumber(const int& regnumber);
    void setproctor(const UniversityStaff& proctorstaff);

    //overloading operator
    Student& operator=(const Student& other);

    //destructor
    ~Student() {}
};
 

#endif

