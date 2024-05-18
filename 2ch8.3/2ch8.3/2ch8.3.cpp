#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std; 

class complex {
private:
	double real;
	double imaginary;
public:
	complex(double newreal, double newimaginary) :real(newreal), imaginary(newimaginary) {};
	complex(double realpart) :real(realpart),imaginary(0){};
	complex() :real(0),imaginary(0){};

	int operator ==(const complex& com)
	{
		return ((real == com.real)  && (imaginary == com.imaginary));
	}

	complex operator +(const complex& com)
	{
		return complex(real + com.real, imaginary + com.imaginary);
	}

	complex operator -(const complex& com)
	{
		return complex(real - com.real, imaginary - com.imaginary);
	}

	complex operator *(const complex& com)
	{
		return complex(real * com.real - imaginary * com.imaginary, real * com.imaginary+imaginary*com.real);
	}

	friend ostream& operator <<(ostream& outputstream, const complex& com)
	{
		outputstream << com.real << "+" << com.imaginary << "*i" << endl;
		return outputstream;
	}

	friend istream& operator >>(istream& inputstream,complex& com)
	{
		inputstream >> com.real >> com.imaginary ;
		return inputstream;
	}

};

int main() {
	complex c1(2, 3);
	complex c2(1, 4);
	//complex c4;
	complex c3 = c1 + c2;
	cout << c3 << endl;
	//cin >> c4;
	return 0;
}