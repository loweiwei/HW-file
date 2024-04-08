#include<iostream>
#include<cmath>
using namespace std;

class weight {
private:
	float pounds;
public:
	void setweightpounds(float p) {
		pounds = p;
	}

	void setweightkilograms(float k) {
		pounds = k * 2.21;
	}

	void setweightounces(float o) {
		pounds = 0 / 16;
	}

	float getweightponds(void) {
		return pounds;
	}
	float getweightkilograms(void) {
		return (pounds / 16);
	}
	float getweightounces(void) {
		return (2.21 * pounds);
	}
};


int main() {
	weight w;
	float weight, p, k, o;
	char scale;
	do {
		cout << "\nselect your scale [pound/kilogram/ounces/exit]\nenter your choice[p/k/o/e]:  ";
		cin >> scale;
		if (scale == 'e') {
			break;
		}
		cout << "enter your weight: ";
		cin >> weight;
		switch (scale) {
		case 'p':
			w.setweightpounds(weight);
			p = w.getweightponds();
			k = w.getweightkilograms();
			o = w.getweightounces();
			cout << "\tPound is: " << p;
			cout << "\n\tKilogram is: " << k;
			cout << "\n\tOunces is: " << o;
			break;
		case 'k':
			w.setweightkilograms(weight);
			p = w.getweightponds();
			k = w.getweightkilograms();
			o = w.getweightounces();
			cout << "\tPound is: " << p;
			cout << "\n\tKilogram is: " << k;
			cout << "\n\tOunces is: " << o;
			break;
		case 'o':
			w.setweightounces(weight);
			p = w.getweightponds();
			k = w.getweightkilograms();
			o = w.getweightounces();
			cout << "\tPound is: " << p;
			cout << "\n\tKilogram is: " << k;
			cout << "\n\tOunces is: " << o;
			break;
		}
	} while (1);
}