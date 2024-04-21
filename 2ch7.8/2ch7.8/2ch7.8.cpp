#include<iostream>
#include<vector>
#include<cstdlib>
#include<conio.h>
using namespace std;


int main() {
	int max = 0;
	int inputval;
	int p[100] = { 0 };
	vector<int>values;
	cout << "enter the grade of students(-1 to quit)\n";
	do {
		cin >> inputval;
		if (inputval == -1) {
			break;
		}
		else {
			values.push_back(inputval);
			if (inputval >= 0) {
				p[inputval]++;
			}
		}

		if (inputval > max) {
			max = inputval;
		}
	} while (1);

	for (int i = max; i >= 0; i--) {
		if (p[i] != 0) {
			cout << "number of " << i << "is" << p[i] << endl;
		}
	}

	//delete p;
	
	return 0;
}