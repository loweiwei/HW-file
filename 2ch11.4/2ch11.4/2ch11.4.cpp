#include<iostream>
#include<cstdlib>
#include"security.h"
using namespace std;

class administrator {
public:
	static int login(string username, string password) {
		int ret;
		ret = security::validate(username, password);
		if (ret == 2) {
			return 1;
		}
		return 0;
	}

};

class User {
public:
	static int login(string username, string password) {
		int ret;
		ret = security::validate(username, password);
		if (ret !=0) {
			return 1;
		}
		return 0;
	}

};

int main() {
	string uname, pw;
	string aname, apw;
	User u;
	administrator a;
	cout << "enter the user name:\n";
	cin >> uname;
	cout << "enter the user password:\n";
	cin >>  pw;
	if (u.login(uname, pw) == 1) {
		cout<<"pass,is user\n";
	}
	else {
		cout << "is not user\n";
	}
	
	cout << endl;

	cout << "enter the administrator name:\n";
	cin >> aname;
	cout << "enter the administrator password:\n";
	cin >> apw;
	if (a.login(aname, apw) == 1) {
		cout << "pass,is administrator\n";
	}
	else {
		cout << "is not administrator\n";
	}

	return 0;
}