#include<iostream>
#include<string>
using namespace std;
// код без объявления переменных, присваиваний, конструкций ветвления и циклов :-)
int getint(int n) {
    cin >> n;
    return n;
}
int f(int i, int n, int p1, int p2, string h1, string h2, int l1, int l2, int x) {
    (n == -1) ? p1 > p2 ? cout << p1 << '\n' << h1 << '\n' : cout << p2 << '\n' << h2 << '\n': cout;
    (n == -1) ? cin : n != 0 ? cin >> x : cin;
    (n == -1) ? 0 : f(i + 1, n - 1, p2, ((p1 > p2 ? l1 : l2) == 0 ? 0 : (p1 > p2 ? p1 : p2)) + x, h2, n == 0 ? (p1 > p2 ? h1 : h2) : ((p1 > p2 ? l1 : l2) == 0 ? "" : (p1 > p2 ? h1 : h2) + " ") + to_string(i), l2 + (n != 0), (p1 > p2 ? l1 : l2) + (n != 0), 0);
}
int main() {
    f(1, getint(0), 0, 0, "", "", 0, 0, 0);
    return 0;
}
