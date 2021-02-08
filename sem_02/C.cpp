#include<iostream>

using namespace std;

int main() {
	int even_cnt = 0;
	int x;
	while (1) {
		cin >> x;
		if (x == 0) break;
		if (x % 2 == 0) even_cnt++;
	}
	cout << even_cnt;
	return 0;
}