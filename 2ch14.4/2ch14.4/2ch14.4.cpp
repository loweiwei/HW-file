#include<iostream>
#include<string>
#include"universitystaff.h"
#include"student.h"
#include"sciencestudent.h"
using namespace std;
#if 0
class UniversityStaff {
public:
    UniversityStaff();
    UniversityStaff(string theName);
    UniversityStaff(const UniversityStaff& theObject);
    string getName() const;
    UniversityStaff& operator=(const UniversityStaff& rtSide) 
    {
        if (this != &rtSide) {
            name = rtSide.getName();
        }
        return *this;
    }

    friend istream& operator >>(istream& inStream, UniversityStaff& staffObject)
    {
        inStream >> staffObject.name;
        return inStream;
    }

    friend ostream& operator <<(ostream& outStream, const UniversityStaff& staffObject)
    {
        outStream << "the UniversityStaff's name is:" << staffObject.getName() << endl;
        return outStream;
    }
private:
    string name;
};



class Student 
{
protected:
    std::string universityName;
    int registrationnumber;
    UniversityStaff proctor;
public:
    //constructor
    Student():universityName(""), registrationnumber(0),proctor(){}
    Student(const string& uniname, int regnumebr, const UniversityStaff& proctorstaff): universityName(uniname), registrationnumber(regnumebr), proctor(proctorstaff){}
    Student(const Student& other): universityName(other.universityName), registrationnumber(other.registrationnumber), proctor(other.proctor) {}

    //accessor
    string getuniversityName()const { return universityName; }
    int getregistrationnumber()const { return registrationnumber; }
    UniversityStaff getproctor()const { return proctor; }
    
    void setuniversityName(const string& uniname) { universityName = uniname;}
    void setregistrationnumber(const int& regnumber) { registrationnumber = regnumber; }
    void setproctor(const UniversityStaff& proctorstaff) { proctor = proctorstaff; }

    //overloading operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            universityName = other.universityName;
            registrationnumber = other.registrationnumber;
            proctor = other.proctor;
        }
    }

    //destructor
   ~Student(){}
};

class sciencestudent : public Student
{
private:
    string sciencediscipline;
    string courselevel;
public:
    //constructor
    sciencestudent() :sciencediscipline(""), courselevel("") {}
    sciencestudent(const string& uniname, int regnumebr, const UniversityStaff& proctorstaff,const  string& scdiscipline,const string& level):
        Student(uniname, regnumebr, proctorstaff), sciencediscipline(scdiscipline), courselevel(level){}
    sciencestudent(const sciencestudent& other) : Student(other), sciencediscipline(other.sciencediscipline), courselevel(other.courselevel){}

    //accessor
    string getsciencediscipline() {return sciencediscipline;}
    string getcourselevel() { return courselevel; }
    void setsciencediscipline(string scdiscipline) { sciencediscipline = scdiscipline; }
    void setcourselevel(string level) { courselevel = level; }

    //overloading operator
    sciencestudent& operator =(const sciencestudent& other)
    {
        if (this != &other) {
            Student::operator =(other);
            sciencediscipline = other.sciencediscipline;
            courselevel = other.courselevel;
        }
        return *this;
    }
    ~sciencestudent() {};
};
#endif // 0

int main() {
    //UniversityStaff class
    UniversityStaff proctor1("Dr.Smith");
    UniversityStaff proctor2("Pf.John");

    cout << "proctor1" << proctor1.getName() << endl;
    cout << "proctor2" << proctor2.getName() << endl;

    //student class
    Student student1("university of abc", 12345, proctor1);
    cout << "student 1:" << student1.getuniversityName() << "," << student1.getregistrationnumber() <<",proctor:"<<student1.getproctor().getName() << endl;

    Student student2;
    student2 = student1;
    cout << "student 2(copy of 1):" << student2.getuniversityName() << "," << student2.getregistrationnumber() << ",proctor:" << student2.getproctor().getName() << endl;
    Student student3;
    student3 = student1;
    cout << "student 3(assigned from student 1):" << student3.getuniversityName() << "," << student3.getregistrationnumber() << ",proctor:" << student3.getproctor().getName() << endl;

    //sciencestudent class
    sciencestudent scistudent1("university of xyz",6789,proctor2,"physics","undergraduate");
    cout << "sciencestudent1:" << scistudent1.getuniversityName() << "," << scistudent1.getregistrationnumber() 
        << ",proctor:" << scistudent1.getproctor().getName() <<","<< scistudent1.getsciencediscipline()<<","<< scistudent1.getcourselevel()<<endl;
    sciencestudent scistudent2 = scistudent1;
    cout << "sciencestudent2(copy of science student 1):" << scistudent2.getuniversityName() << "," << scistudent2.getregistrationnumber()
        << ",proctor:" << scistudent2.getproctor().getName() << "," << scistudent2.getsciencediscipline() << "," << scistudent2.getcourselevel() << endl;
    sciencestudent scistudent3;
    scistudent3  = scistudent1;
    cout << "sciencestudent2(assigned of science student 1):" << scistudent3.getuniversityName() << "," << scistudent3.getregistrationnumber()
        << ",proctor:" << scistudent3.getproctor().getName() << "," << scistudent3.getsciencediscipline() << "," << scistudent3.getcourselevel() << endl;

    return 0;
}