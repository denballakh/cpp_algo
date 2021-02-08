#include<iostream>
#include<string>

using namespace std;

string ten = "<";
string one = "v";
string sep = ".";

string digit(int n) {
	string res = "";
	while (n >= 10) {
		n -= 10;
		res += ten;
	}
	while (n >= 1) {
		n -= 1;
		res += one;
	}
	return res;
}

int main() {
	int n;
	string res = "";

	cin >> n;
	res = digit(n % 60);
	n = n / 60;
	while (n) {
		res = digit(n % 60) + sep + res;
		n = n / 60;
	}
	cout << res;
	return 0;
}