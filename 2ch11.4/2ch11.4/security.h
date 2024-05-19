#ifndef security_h
#define security_h


#include<iostream>
#include<cstdlib>
using namespace std;

class security {
public:
	static int validate(string username, string password) {
		if ((username == "abbott") && (password == "monday")) { return 1; }
		if ((username == "costello") && (password == "tuesday")) { return 2; }
		return 0;
	}

}; 


#endif