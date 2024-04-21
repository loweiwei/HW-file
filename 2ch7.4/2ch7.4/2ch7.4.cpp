#include<iostream>
#include<cstdlib>
using namespace std;

class hotdogstand {
private:
	int idnumber = 0;
	int num_of_sold = 0;
	static int totalhotdogsold;
public:
	hotdogstand() {
		idnumber = 0;
		num_of_sold = 0;
		totalhotdogsold += num_of_sold;
	}

	hotdogstand(int id, int numsold) {
		idnumber = id;
		num_of_sold = numsold;
		totalhotdogsold += numsold;
	}
	int getid() {
		return idnumber;
	};

	void setid(int newid) {
		idnumber = newid;
	};

	void justsold() {
		num_of_sold = 1;
		totalhotdogsold++;
	};

	void justsold(int count) {
		num_of_sold = count;
		totalhotdogsold+=count;
	};
	int  turnsold() {
		return num_of_sold;
	};
	int gettotalsold() {
		return totalhotdogsold;
	};
};

int hotdogstand::totalhotdogsold = 0;

int main() {
	hotdogstand stand1(1, 0), stand2(2, 0), stand3(3, 0),stand4;
	stand1.justsold();
	stand2.justsold();
	stand3.justsold();
	stand4.justsold();
	cout << "stand" << stand1.getid() << "sold" << stand1.turnsold() << endl;
	cout << "stand" << stand2.getid() << "sold" << stand2.turnsold() << endl;
	cout << "stand" << stand3.getid() << "sold" << stand3.turnsold() << endl;
	cout << "stand" << stand4.getid() << "sold" << stand4.turnsold() << endl;

	cout << "totalofhotdog:" << stand1.gettotalsold() << endl;

	stand1.justsold();
	stand3.justsold();
	stand2.justsold(5);
	stand4.setid(4);
	stand1.setid(99);

	cout << "stand" << stand1.getid() << "sold" << stand1.turnsold() << endl;
	cout << "stand" << stand2.getid() << "sold" << stand2.turnsold() << endl;
	cout << "stand" << stand3.getid() << "sold" << stand3.turnsold() << endl;
	cout << "stand" << stand4.getid() << "sold" << stand4.turnsold() << endl;

	cout << "totalofhotdog:" << stand1.gettotalsold() << endl;
	return 0;

}