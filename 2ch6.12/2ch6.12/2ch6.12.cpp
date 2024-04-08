#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

class boxofproduce {
private:
	string items[3];
public:
	string getitem(int index);
	void setitem(int index, string item);
	void displaycontexts();
};

//input index and return the item
string boxofproduce::getitem(int index) {
	return items[index];
}

//input the turget index and input change item
void boxofproduce::setitem(int index, string item) {
	items[index] = item;
}

//show the item list
void boxofproduce::displaycontexts() {
	cout << "box contain:";
	for (int i = 0; i < 3; i++) {
		cout << items[i] << " ";
	}
	cout << endl;
}

int main() {

	//random number
	srand(time(NULL));

	//get the data from the file
	string full_list[5];
	ifstream file;
	file.open("list.txt");
	file >> full_list[0] >> full_list[1] >> full_list[2] >> full_list[3] >> full_list[4];


	boxofproduce box;

	//input random list
	for (int i = 0; i < 3; i++) {
		box.setitem(i, full_list[rand() % 5]);
	}

	//show
	box.displaycontexts();

	//change
	cout << "enter the item you want to replace and the new item ";
	string olditem, newitem;
	cin >> olditem >> newitem;

	//change
	for (int i = 0; i < 3; i++) {
		if (box.getitem(i) == olditem) {
			cout << "\n" << i << endl;
			box.setitem(i, newitem);
			break;
		}
	}

	//show
	box.displaycontexts();
	return 0;
}

	

	