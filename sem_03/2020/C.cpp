#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int min_min=1000001, min_max=1000001, max_min=0, max_max=0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= min_min) {
            min_max = min_min;
            min_min = x;
        }
        if (x <= min_max && x > min_min) {
            min_max = x;
        }
        if (x >= max_max) {
            max_min = max_max;
            max_max = x;
        }
        if (x >= max_min && x < max_max) {
            max_min = x;
        }
    }
    cout << min_min + min_max << ' ' << max_min + max_max << endl;
    return 0;
}