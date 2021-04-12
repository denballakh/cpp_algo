#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double sumX = 0.0;
    double sumX2 = 0.0;
    int cnt = 0;

    while (1) {
        double x;
        cin >> x;
        if (x == 0) break;

        sumX += x;
        sumX2 += x*x;
        cnt += 1;
    }

    double mx = sumX / cnt;
    double dx = sumX2 / cnt - mx * mx;
    // cout << round(1000 * mx) / 1000 << " " << round(1000 * dx) / 1000 << endl;
    printf("%.3f %.3f\n", mx, dx);

    return 0;
}
