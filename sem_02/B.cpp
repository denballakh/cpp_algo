#include<iostream>

using namespace std;
// Год является високосным, если его номер кратен 4, но не кратен 100, а также если он кратен 400
int main() {
	int year;
	bool result;
	cin >> year;
	result = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (result) cout << "YES";
	else cout << "NO";
	return 0;
}