#include <iostream>
#include<cstring>
using namespace std;

class pizza {
private:
    string typeofpizza;
    char sizeofpizza;
    int numberofpepperonicheese;
    double price;
public:
    void outputdescrtption();
    void getinputs();
    void computerprice();
    void printresult();

};

void pizza::outputdescrtption() {
    cout << "Small pizza = $10+$2 per topping" << endl;
    cout << "Medium pizza = $14+$2 per topping" << endl;
    cout << "Large pizza = $17+$2 per topping" << endl;
}
void pizza::getinputs() {
    cout << "Enter the type of pizza(1:depp dish,2:hand tossed,3:pan):" << endl;
    cin >> typeofpizza;
    getchar();
    cout << "Enter the size of pizza(large = l,medium = m,small = s):" << endl;
    cin >> sizeofpizza;
    getchar();
    cout << "Enter the number of pepperoni or cheese toppings: " << endl;
    cin >> numberofpepperonicheese;
}
void pizza::computerprice() {
    switch (sizeofpizza) {
    case 's':
        price = 10 + numberofpepperonicheese * 2;
        break;
    case'm':
        price = 14 + numberofpepperonicheese * 2;
        break;
    case'l':
        price = 17 + numberofpepperonicheese * 2;
        break;
    }
}
void pizza::printresult() {
    cout << "Pizza type:" << typeofpizza << endl;
    cout << "Number of Pepperoni or Cheese is: " << numberofpepperonicheese << endl;
    cout << "Size of Pizza: " << sizeofpizza << endl;
    cout << "---------------------------" << endl;
    cout << "The total price is:" << price << endl;
}
int main() {
    pizza p;
    p.outputdescrtption();
    cout << "------------------\n";
    p.getinputs();
    p.computerprice();
    p.printresult();
    return 0;
}