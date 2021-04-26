#include<iostream>

int f(int n, int k, bool b = 1) {
    return n <= 0 ? 0 : n == 1 ? b ? k - 1 : k : (k - 1) * f(n - 1, k, 0) + f(n - 1, k) * (!b); // работает - не трогай :-)
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << f(n, k) << '\n';
    return 0;
}
