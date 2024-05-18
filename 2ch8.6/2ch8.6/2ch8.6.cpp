
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class myinterger {
private:
	int integer;
public:
	myinterger() :integer(0) {}
	myinterger(int t) :integer(t) {}
	//set
	void setinteger(int t) { integer = t; }
	//get
	int getinteger() {
		return integer;
	}

	//[]
	int operator [](const int index) {
		int n = integer;
		int k = integer;
		int size = 0;
		do {
			n = n / 10;
			size++;
		} while (n != 0);

		if (n >= size) {
			return -1;
		}
		else {

			k = k - integer / pow(10, (index + 1));
			k = k / pow(10, index);
			return k;
		}

	}



};

int main() {
	myinterger t1;
	int num;
	int idx;
	cout << "enter the integer:";
	cin >> num;
	t1.setinteger(num);

	cout << "enter the index you want to find:";
	cin >> idx;
	if (t1[idx]) {
		cout << t1[idx];
	}
	else {
		cout << "the index position is out of range";
	}

	return 0;
}