#include<iostream>

using namespace std;

int main() {
	int max_even = 0;
	int x;
	while (1) {
		cin >> x;
		if (x == 0) break;
		if (x % 2 == 0 && x > max_even) max_even = x;
	}
	cout << max_even;
	return 0;
}