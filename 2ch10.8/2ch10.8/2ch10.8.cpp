#include<iostream>
#include<vector>
using namespace std;

class television {
private:
	int nummodel;
	string displaytype;
	double dimension;
	vector<string> connectmodel;
public:
	television() :displaytype(""), dimension(0.0) {}
	television(string t,double d,vector<string> m) :displaytype(t), dimension(d), connectmodel(m){}

	//get
	string getdisplaytype() { return displaytype; }
	int  getdimension() { return dimension; }
	vector<string>  connectmodel() { return  connectmodel; }

	//set
	void setdisplaytype(string t) { displaytype = t; }
	void setdimension(double d) { dimension =d; }
	void setconnectmodel(vector<string> list) { connectmodel = list; }


	void inputdata() {
		cout << "enter the television displaytype:" << endl;
		cin >> displaytype;
		cout << "enter the television dimension:" << endl;
		cin >> dimension;
		cout << "how many model do you like to enter:" << endl;
		cin >> nummodel;
		connectmodel.resize(nummodel);
		for (int i = 0; i < nummodel; i++) {
			cout << "enter the " << i + 1 << "connectmodel's name:" << endl;
			cin >> connectmodel[i];
		}
	}

	void outputdata() {
		cout << "the television displaytypeis:" << displaytype << endl;
		cout << "the television dimension:" << dimension;
		cout << "connect model name of television:\n";
		for (int i = 0; i <nummodel; i++) {
			cout << "model " << i + 1 << " name:" << connectmodel[i] << endl;
		}
	}

	void resettelevision() {
		displaytype = "";
		dimension = 0;
		connectmodel.clear();
	}

	television& operator =(const television& s) {
		if (this != &s) {
			displaytype = s.displaytype;
			dimension = s.dimension;
			connectmodel = s.connectmodel;
		}
		return *this;
	}
	~television() {};
};

int main() {
	television ta, tb;
	int numtv;

	ta.inputdata();
	cout << "ta data is:" << endl;
	ta.outputdata();

	tb = ta;
	cout << "tb data(after tb = ta) is:" << endl;
	tb.outputdata();


	cout << "how many television do you like to create?";
	cin >> numtv;

	television t[numtv];
	
}