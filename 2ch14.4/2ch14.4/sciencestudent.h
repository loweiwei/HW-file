#ifndef sciencestudent_h
#define sciencestudent_h
#include "student.h"
#include<string>
using namespace std;

class sciencestudent : public Student
{
private:
    string sciencediscipline;
    string courselevel;
public:
    //constructor
    sciencestudent();
    sciencestudent(const string& uniname, int regnumebr, const UniversityStaff& proctorstaff, const  string& scdiscipline, const string& level);
    sciencestudent(const sciencestudent& other);

    //accessor
    string getsciencediscipline();
    string getcourselevel();
    void setsciencediscipline(string scdiscipline);
    void setcourselevel(string level);

    //overloading operator
    sciencestudent& operator =(const sciencestudent& other);
    ~sciencestudent() {};
};
#endif // !1

