#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

class postalcode {
private:
	int zipcode;
	string barcode;

	int check5twoone()
	{
		int fivecase[5];
		int count ;
		for (int i = 1; i < 25;i+=5 ) {
			count = 0;
			for (int j = i; j <= i+ 4; j++) {
				if (static_cast<int>(barcode[j])-48 == 1) {
					count++;
				}
			}
			if (count != 2) {
				return 0;
			}
		}
		return 1;
	}
	int checkbarcode()
	{
		if (barcode.length() == 27 && static_cast<int>(barcode[0])-48 == 1  &&static_cast<int>( barcode[26])-48 == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int  caculatebarcode()
	{
		int list[5] = { 7,4,2,1,0 };
		int total;
		vector<int> total_5;
		//string bcode;
		int counter;
		for (int i = 1; i <= 25; i += 5) {
			counter = 0;
			total = 0;
			for (int j = i; j <= i + 4; j++) {
				counter++;
				if (static_cast<int>(barcode[j]) - 48 == 1) {
					total += list[counter - 1];
				}
		
			}
			if (total == 11) {
				total = 0;
			}
			total_5.push_back(total);

		}
		for (int i = 0; i < 5; i++) {
			//bcode[i] = total_5[i];
			total += static_cast<int>(total_5[i])*pow(10,4-i);
		}
		return total;

	}

	string getfivedigitvalue()
	{
		string result = "1";
		int number = zipcode;
		int diliver = 10000;
		int z_code[5];
		for (int i = 0; i < 5; i++) {
			z_code[i] = number / diliver;

			switch (z_code[i]) {
			case 0:
				result += "11000";
				break;
			case 1:
				result += "00011";
				break;
			case 2:
				result += "00101";
				break;
			case 3:
				result += "00110";
				break;
			case 4:
				result += "01001";
				break;
			case 5:
				result += "01010";
				break;
			case 6:
				result += "01100";
				break;
			case 7:
				result += "10001";
				break;
			case 8:
				result += "10010";
				break;
			case 9:
				result += "10100";
				break;
			default:
				result += "00000";
				cout << "Error!" << endl;
				break;
			}
			number = number % diliver;
			diliver = diliver / 10;
			cout << z_code[i] << endl;
			//cout << number << endl;
			cout << "{"<<result<<endl;
		}
		result += "1";
		return result;
	}

public:
	postalcode(int zip):zipcode(zip){}
	postalcode(string bar):barcode(bar){}

	int getzipcode()
	{
		if (checkbarcode()) {
			if (check5twoone()) {
				return caculatebarcode();
			}
			else {
				cout << "there are some error in the barcode,please check again.\n";
				return 0;
			}
		}else{
			cout << "there are some error in the barcode,please check again.\n";
			return 0;
		}
	}

	string getbarcode()
	{
		return getfivedigitvalue();
	}

};



int main() {
	postalcode b("110100101000101011000010011");
	cout << "the zip code is : " << b.getzipcode() << endl;

	postalcode z(99504);
	cout << "the bar code is" << z.getbarcode() << endl;
	return 0;

}