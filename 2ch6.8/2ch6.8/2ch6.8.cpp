#include <iostream>
using namespace std;

class money {
private:
    int dollar;
    int cent;
public:
    void readinput(int d, int c);
    void setinput();
    double monetaryamount();

};

void money::readinput(int d, int c)
{
    dollar = d;
    cent = c;
}

double money::monetaryamount()
{
    return dollar + cent / 100.0;
}

void money::setinput()
{
    cout << "dollar:" << dollar << endl;
    cout << "cent:" << cent << endl;
}
int main() {
    money m;
    m.readinput(4, 45);
    m.setinput();
    cout << "total dollar is:" << m.monetaryamount();
}