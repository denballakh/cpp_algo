#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n;) {
		if (n % i == 0) {
			cout << i << '\n';
			n = n / i;
		} else i++;
	}
	return 0;
}