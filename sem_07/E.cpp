#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;;
    vector<vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[n - j - 1][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
