#include<iostream>
#include<string>

using namespace std;

string ten = "<";
string one = "v";
string sep = ".";

string digit(int n) {
    if (n >= 10) return ten + digit(n - 10);
    if (n >= 1) return one + digit(n - 1);
    return "";
}

string number(int n) {
    if (n < 60) return digit(n);
    return number(n / 60) + sep + digit(n % 60);
}

int main() {
	int n;
	cin >> n;
	cout << number(n);
	return 0;
}