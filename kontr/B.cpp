#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int* data = new int[n];
    for (int i = 0; i < n; i++)
        cin >> data[i];

    int pos = -1;
    for (int i = 0; i < n; i++)
        if (data[i] == k)
            pos = i + 1;

    cout << pos << endl;

    return 0;
}
