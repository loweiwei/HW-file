#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class prime {
private:
	int p;
	int p__(int p) {
		int k = p;
		while (1) {
			//int k = p;
			k++;
			int count = 0;
			for (int i = 1; i < k; i++) {
				if (k % i == 0) {
					count++;
				}
			}
			if (count == 1) {

				return k;
			}
		}
	}
	int __p(int p) {
		while (1) {
			p--;
			int count = 0;
			for (int i = 1; i < p; i++) {
				if (p % i == 0) {
					count++;
				}
			}
			if (count == 1) {
				return p;
			}
		}
	}

	int isprime(int num) {
		int count = 0;
		for (int i = 1; i < num; i++) {
			if (num % i == 0) {
				count++;
			}
		}
		if (count == 1) {
			return 1;
		}
		else {
			return -1;
		}
	}

public:
	prime() :p(1) {}
	prime(int num) :p(num) {};

	void setprime(int num) {
		if (isprime(num)) {
			p = num;
		}
		else {
			cout << "it is not prime number\n";
		}
	}

	int getprime() { return p; }

	prime  operator++(int) {
		prime number;
		number.p = p__(p);
		return number;
	}

	prime operator--(int) {
		prime number;
		number.p = __p(p);
		return number;
	}
};

int main() {
	prime number1(4), number2;
	number1.setprime(13);
	cout << number1.getprime();
	//cout << number1.getprime();
	number2 = number1++;
	cout << number1.getprime();

	cout << number2.getprime();
	return 0;
}
