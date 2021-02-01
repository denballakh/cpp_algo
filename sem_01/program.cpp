#include<iostream>

using namespace std;

bool f1(int x, int y, int n) {
    // ***
    // ***
    // ***
    return 1;
}

bool f2(int x, int y, int n) {
    // ***
    // **
    // *
    return x + y < n;
}

bool f3(int x, int y, int n) {
    // ***
    //  **
    //   *
    return x >= y;
}

bool f4(int x, int y, int n) {
    //  * *
    // * *
    //  * *
    // * *
    return (x + y) % 2;
}

bool f5(int x, int y, int n) {
    // ***
    //  *
    //
    return x >= y && x + y < n;
}

bool f6(int x, int y, int n) {
    // ********
    // * * * *
    // **  **
    // *   *
    // ****
    // * *
    // **
    // *
    return !(x & y);
}

bool f7(int x, int y, int n) {
    return (x | y) & n;
}



int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            if (f6(j, i, n)) c = '*';
            else c = ' ';
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
