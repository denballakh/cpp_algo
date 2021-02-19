#include<iostream>

using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    cout << do_some_awesome_work(&a, &b);
    return 0;
}

int do_some_awesome_work(int* a, int* b) {
    return *a * *a + *b * *b;
}