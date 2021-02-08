#include<iostream>
#include<string>

using namespace std;

string id_chief = "A999AA";
int speed_limit = 60;

int tax(string id) {
	if (id[1] == id[2] && id[2] == id[3]) return 1000;
	if (id[1] == id[2] || id[2] == id[3] || id[3] == id[1]) return 500;
	return 100;
}

int main() {
	string id;
	int speed;
	int sum = 0;
	while (1) {
		cin >> speed >> id;
		if (id == id_chief) break;
		if (speed <= speed_limit) continue;
		sum += tax(id);
	}
	cout << sum;
	return 0;
}