#include<iostream>
#include<cstdlib>
using namespace std;

class retangle {
private:
	int id;
	double length;
	double width;
	static int num;
public:
	retangle():length(1),width(1){}
	retangle(int newid, double newlength, double newwidth):id(newid) {
		
	}
	void setid(int newid) { this->id = newid; }
	void setlength(double newlength) { this->length = newlength; }
	void setwidth(double newwidth) { this->width = newwidth; }
	static int getnum() {
		num++;
		return num;
	}
	int getid() { return this->id;}
	double getlength() { return this->length;}
	double getwidth() { return this->width;}
	double getpar() { return (this->length + this->width) * 2; }
	double getarea() {
		return this->length * this->width;}

};

int retangle::num = 0;

class cuboid {
private:
	retangle ret;
	double den;
	double height;

public:
	cuboid() :ret(), den(1), height(1){}
	cuboid(double newlength, double newwidth, double newden, double newheight) {
		this->ret.setlength(newlength);
		this->ret.setwidth(newwidth);
		this->den = newden;
		this->height = newheight;
	}
	void setden(double newden) {
		this->den = newden;
	}
	void setheight(double newheight) {
		this->height = newheight;
	}

	double getden() {
		return this->den;
	}

	double getheight() {
		return this->height;
	}
	double getvol() {
		return this->ret.getarea() * this->getheight();
	}

	double getweight() {
		return this->getvol() * this->getden();
	}

	int compvol(cuboid& newcuboid) {
		if (this->getvol() > newcuboid.getvol()) {
			return 1;
		}
		else {
			return 0;
		}
	}

	

	void showcuboidinf() {
		cout << "Length: " << this->ret.getlength() << endl;
		cout << "Width: " << this->ret.getwidth() << endl;
		cout << "Height: " << this->getheight() << endl;
		cout << "Volume: " << this->getvol() << endl;
		cout << "Weight: " << this->getweight() << endl;
	}
};
int comcubweight(cuboid& cuboid_a, cuboid& cuboid_b) {
	if (cuboid_a.getweight() > cuboid_b.getweight()) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	cuboid cuboid_1(3.2, 9.8, 15.6, 0.8), cuboid_2(5.2, 7.6, 10.2, 1.2);
	cout << "cuboid_a:" << endl;
	cuboid_1.showcuboidinf();
	cout << endl << "Cuboid 2 :" << endl;
	cuboid_2.showcuboidinf();
	cout << endl;

	if (cuboid_1.compvol(cuboid_2)) {
		cout << "Cuboid 1 is bigger than Cuboid 2." << endl;
	}
	else
	{
		cout << "Cuboid 2 is bigger than Cuboid 2." << endl;
	}

	if (comcubweight(cuboid_1, cuboid_2))
	{
		cout << "Cuboid 1 is heavier than cuboid 2." << endl;
	}
	else
	{
		cout << "Cuboid 2 is heavier than Cuboid 1." << endl;
	}
	return 0;
}