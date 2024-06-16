#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class dice {
public:
	dice() :numside(6) { srand(time(NULL)); }
	dice(int numside) :numside(numside) { srand(time(NULL)); }
	virtual int rolldice()const
	{
		return rand() % numside + 1;
	}
protected:
	int numside;
};

class LoadedDice :public dice{
public:
	LoadedDice():dice(){}
	LoadedDice(int numside) :dice(numside) {};
	int rolldice() const override {
		if (rand() % 2 == 0) {
			return numside;
		}
		else {
			return dice::rolldice();
		}
	}
};

int rollTwoDice(const dice& die1, const dice& die2)
{
	return die1.rolldice() + die2.rolldice();
}

int main() {
	dice dice1(6);
	dice dice2(8);

	cout << "rolling two  standard dice" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Roll " << i + 1 << ": " << rollTwoDice(dice1, dice2) << endl;
	}

	LoadedDice loadedDie1(6);
	LoadedDice loadedDie2(8);

	cout << "\nRolling two loaded dice:" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << "Roll " << i + 1 << ": " << rollTwoDice(loadedDie1, loadedDie2) << endl;
	}

	return 0;
}