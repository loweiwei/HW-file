#include <iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
    string str;

    while (true) {
        cout << "Enter the sentance,type 'quit'to exit" << endl;
        getline(cin, str);
        int b = 0;
        int n = str.length();
        while (b < n) {
            while (b < n && !isalpha(str[b])) {
                b++;
            }
            int e = b + 1;
            while (b < n && isalpha(str[e])) {
                e++;
            }
            if (e - b == 4) {
                if (isupper(str[b])) {
                    str.replace(b, 4, "Love");
                }
                else {
                    str.replace(b, 4, "love");
                }
            }
            b = e;
        }
        cout << "Output:" << endl;
        cout << str << endl << endl;
    }
}