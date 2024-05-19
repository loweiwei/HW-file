#include<iostream>
#include<cstdlib>
using namespace std;

class television {
public:
	string displaytype;
	double dimension;
	string* connectivitysupport;
public:
	television() :displaytype(""), dimension(0.0), connectivitysupport(NULL) {}
	television(string d, double m, string* c) :displaytype(d), dimension(m), connectivitysupport(c) {}
	television(const television& tv) {
		displaytype = tv.displaytype;
		dimension = tv.dimension;

		if (connectivitysupport) {
			delete[] connectivitysupport;
			connectivitysupport = NULL;
		}

		connectivitysupport = new string[3];

		for (int i = 0; i < 3; i++) {
			connectivitysupport[i] = tv.connectivitysupport[i];
		}
	}
	//set
	void setdisplaytype(string type) {
		displaytype = type;
	}
	void setdimension(double m) {
		dimension = m;
	}
	void setconnectivitysupport(string* c) {
		connectivitysupport = c;
	}
	//get
	string getdisplaytyp() {
		return displaytype;
	}
	double setdimension() {
		return dimension;
	}
	string* setconnectivitysupport() {
		return connectivitysupport;
	}

	void inputdata() {
		cout << "enter the displaytype:";
		cin >> displaytype;
		cout << endl;
		cout << "enter the dimension:";
		cin >> dimension;
		cout << endl;

		if (connectivitysupport) {
			delete[] connectivitysupport;
			connectivitysupport = NULL;
		}

		connectivitysupport = new string[3];
		cout << "enter three model of connectivitysupport:\n";
		for (int i = 0; i < 3; i++) {
			cout << "model" << i + 1 << ":";
			cin >> connectivitysupport[i];
		}
	}

	void outputdata() {
		cout << "displaytype:" << displaytype << endl;;
		cout << "dimension:" << dimension << endl;
		cout << "three model of connectivitysupport:\n";
		for (int i = 0; i < 3; i++) {
			cout << "model" << i + 1 << ":" << connectivitysupport[i] << endl;
		}
	}
};


int main() {
	television t1, t2, t;
	int numtel;
	television** location;
	t1.inputdata();
	t1.outputdata();

	cout << "how many television1 do you want to create?";
	cin >> numtel;

	location = new television*[numtel];
	for (int i = 0; i < numtel; i++) {
		location[i] = new television(t1);
	}


	cout << "enter the name of model:" << endl;
	for (int i = 0; i < numtel; i++) {
		cout << "television" << i + 1 << endl;
		location[i]->outputdata() ;
	}
	return 0;
}