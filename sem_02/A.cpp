#include<iostream>

using namespace std;

int gcd(int a, int b) {
    if (a && b) return gcd(b, a % b);
    else return a | b;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);
	return 0;
}