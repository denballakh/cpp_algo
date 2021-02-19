#include<iostream>

using namespace std;

int main() {
    int cnt[4] = {0, 0, 0, 0};
    int n;
    int x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x * y == 0) continue;
        int px = x > 0, py = y > 0;
        cnt[px + 2 * py]++;
    }
    int max = -1, max_i;
    for (int i = 0; i < 4; i++) {
        if (cnt[i] > max) {
            max = cnt[i];
            max_i = i;
        }
    }
    switch(max_i) {
        case 0: max_i = 3; break;
        case 1: max_i = 4; break;
        case 2: max_i = 2; break;
        case 3: max_i = 1; break;
    }
    cout << max_i << ' ' << max << endl;
    return 0;
}