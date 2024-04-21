#include<iostream>
#include<cstdlib>
using namespace std;

class retangle {
private:
	static int num_of_retangle;
	int id;
	double length;
	double width;
public:
	retangle() {
		length = 1;
		width = 1;
	}
	retangle(int newid, double newlength, double newwidth) {
		id = newid;
		this->setlength(newlength);
		this->setwidth(newwidth);
	}

	void setid(int newid) {
		this -> id = newid;
	}

	void setlength(double newlength) {
		double checklength = newlength;
		int tf = 1;
		while (tf) {
			if (checklength < 0.0 || checklength >10.0) {
				cout << "length should be from 0 to 10.\n";
				cout << "length: ";
				cin >> checklength;
			}
			else {
				tf = 0;
				this->length = newlength;
			}
		}
	}
	void setwidth(double newwidth) {
		double checkwidth = newwidth;
		int tf = 1;
		while (tf) {
			if (checkwidth < 0.0 || checkwidth >10.0) {
				cout << "width should be from 0 to 10.\n";
				cout << "width: ";
				cin >> checkwidth;
			}
			else {
				tf = 0;
				this->width = newwidth;
			}
		}
	}

	static int getnum() {
		num_of_retangle++;
		return num_of_retangle;
	}
	int getid() {
		return this->id;
	}
	double getlength() {
		return this->length;
	}
	double getwidth() {
		return this->width;
	}
	double getarea() {
		return this->getlength() * this->getwidth();
	}
	double getperimeter() {
		return (this->getlength() + this->getwidth()) * 2;
	}

	void showinf() {
		cout << "ID: " << this->getid() << endl;
		cout << "Length: " << this->getlength() << endl;
		cout << "Width: " << this->getwidth() << endl;
		cout << "Perimeter: " << this->getperimeter() << endl;
		cout << "Area: " << this->getarea() << endl << endl;
	}
};

int retangle::num_of_retangle = 0;

int main(void) {
	int id;
	double length;
	double width;

	retangle retangle_1;
	cout << "enter retangle_1 length and width:" << endl;
	retangle_1.setid(retangle::getnum());
	cout << "length:";
	cin >> length;
	retangle_1.setlength(length);
	cin >> width;
	retangle_1.setwidth(width);


	id = retangle::getnum();
	retangle retangle_2(id, 1, 1);
	cout << "enter retangle_2 length and width:" << endl;
	cout << "length:";
	cin >> length;
	retangle_2.setlength(length);
	cin >> width;
	retangle_2.setwidth(width);

	id = retangle::getnum();
	cout << "enter retangle_3 length and width:" << endl;
	cout << "length:";
	cin >> length;
	while (1){
		if (length < 0.0 || length>10.0) {
			cout << "length is out of range,enter again:";
			cout << "length:";
			cin >> length;
		}
		else {
			break;
		}
	}

	cin >> width;
	while (1) {
		if (width < 0.0 || width>10.0) {
			cout << "width is out of range,enter again:";
			cout << "width:";
			cin >> width;
		}
		else {
			break;
		}
	}

	retangle retangle_3(id, length, width);

	cout << endl;

	retangle_1.showinf();
	retangle_2.showinf();
	retangle_3.showinf();

	return 0;

}