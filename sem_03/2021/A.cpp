#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (a[i] * n > sum) * a[i];
    cout << cnt;
    return 0;
}
