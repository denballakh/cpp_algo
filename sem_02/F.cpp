#include<iostream>

using namespace std;

int main() {
	int max = -1;
	int max_cnt = 0;
	int x;
	while (1) {
		cin >> x;
		if (x == 0) break;
		if (x > max) {
			max = x;
			max_cnt = 0;
		};
		if (x == max) max_cnt++;
	}
	cout << max_cnt;
	return 0;
}