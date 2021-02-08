#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int bit_cnt = 0;
	for (int i = 0; i < 31; i++) {
		if (n & (1 << i)) bit_cnt++;
	}
	if (bit_cnt == 1) cout << "YES";
	else cout << "NO";
	return 0;
}