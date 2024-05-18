#include<iostream>
using namespace std;


class subscriber {
private:
	string name;
	int numchannel;
	string* channelist;
public:
	subscriber() :name(""), numchannel(0), channelist(NULL){}
	subscriber(string n,int num,string* list):name(n),numchannel(num),channelist(list){}

	void setname(string n) {
		name = n;
	}
	void setnumchannel(int num) {
		numchannel = num;
	}
	void setchannelist(string* list) {
		channelist = list;
	}

	string getname() {
		return name;
	}
	int getnumchannel() {
		return numchannel;
	}
	string* getchannelist() {
		return channelist;
	}

	void inputdata() {
		cout << "\nenter the subscriber's name:";
		cin >> name;
		cout << "\nenter the number of channel;";
		cin >> numchannel;
		if (channelist) {
			delete[]channelist;
			channelist = NULL;
		}

		channelist = new string[numchannel];
		if (channelist == NULL) {
			cout << "Error: Insufficient memory" << endl;
			exit(1);
		}
		cout << "channel's name" << endl;
		for (int i = 0; i < numchannel; i++) {
			cout << "\nenter the " << i + 1 << "channel name:";
			cin >> channelist[i];
		}
	}

	void outputdata() {
		cout << "\nsubscriber name:" << name;
		cout << "\nsubscribrt subscribe channel number:" << numchannel;
		cout << "\nsubscribrt subscribe channel name:";
		for (int i = 0; i < numchannel; i++) {
			cout << channelist[i] << endl;
		}
	}

	void resetsubscriber() {
		name = "";
		numchannel = 0;
		delete[]channelist;
		channelist = NULL;
	}

	subscriber &operator = (const subscriber & sub){
		name = sub.name;
		numchannel = sub.numchannel;

		delete[]channelist;
		channelist = NULL;

		channelist = new string[sub.numchannel];
		for (int i = 0; i < numchannel; i++) {
			channelist[i] = sub.channelist[i];
		}

		return *this;
		//channelist = sub.channelist;
	}

	~subscriber() {
		if (channelist) {
			delete[]channelist;
			channelist = NULL;
		}
	}
};


int main() {
	subscriber s1, s2;

	s1.inputdata();
	s1.outputdata();

	s1 = s2;
	s1.outputdata();

	s1.resetsubscriber();
	s1.outputdata();

	return 0;

}













































/*class subscriber {
private:
	string name;
	int numchannel;
	string* channelist;
public:
	subscriber() :name(""), numchannel(0),channelist(NULL) {}
	subscriber(string s, int n, string* l) :name(s), numchannel(n), channelist(l) {};

	//get
	string getname() { return name; }
	int  getnumchannels() { return numchannel; }
	string* getchannelist() { return channelist; }

	//set
	void setname(string n) { name = n; }
	void setnumchannel(int num) { numchannel = num; }
	void setchannelist(string* s) { channelist = s; }


	void inputdata() {
		cout << "enter the subscriber's name:" << endl;
		cin >> name;
		cout << "enter the number of channel:" << endl;
		cin >> numchannel;
		
		//
		if (channelist) {
			cout << "delete channelist 0" << &channelist << endl;
		}
	}

	void outputdata() {
		cout << "the subscriber's name is:" << getname << endl;
		cout << "the number of channel of subscriber subscibe:" << getnumchannels;
		cout << "channel name of subscriber subscibe:\n";
		for (int i = 0; i < numchannel; i++) {
			cout << "channel's " << i + 1 << " name:" << channelist[i]<<endl;
		}
	}

	void resetsubscriber() {
		name = "";
		numchannel = 0;
		channelist.clear();
	}

	subscriber& operator =(const subscriber& s){
		if (this != &s) {
			name = s.name;
			numchannel = s.numchannel;
			channelist = s.channelist;
		}
		return *this;
	}
	~subscriber() {};
};

int main() {
	subscriber s1, s2;

	s1.inputdata();
	cout << "student 1's data is:" << endl;
	s1.outputdata();

	s2 = s1;
	cout << "student 2's data(after s1 = s2) is:" << endl;
	s2.outputdata();
	

	s1.resetsubscriber();
	cout << "student 1's data(after reset) is:" << endl;
	s1.outputdata();

	cout << "student 2's data(after s1 reet) is:" << endl;
	s2.outputdata();
	return 0;

}*/