#include<iostream>

using namespace std;

int f(int n, int m, int y, int x) {
    return (0 <= y && y <= n - 1) && (0 <= x && x <= m - 1);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int field[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            field[i][j] = 0;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        field[y-1][x-1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 1) {
                cout << -1 << ' ';
                continue;
            }
            int cnt = 0;
            cnt = 
                (f(n, m, i-1, j-1) ? field[i-1][j-1] : 0) + 
                (f(n, m, i-1, j  ) ? field[i-1][j  ] : 0) + 
                (f(n, m, i-1, j+1) ? field[i-1][j+1] : 0) + 
                (f(n, m, i  , j-1) ? field[i  ][j-1] : 0) + 
                (f(n, m, i  , j+1) ? field[i  ][j+1] : 0) + 
                (f(n, m, i+1, j-1) ? field[i+1][j-1] : 0) + 
                (f(n, m, i+1, j  ) ? field[i+1][j  ] : 0) + 
                (f(n, m, i+1, j+1) ? field[i+1][j+1] : 0);

            cout << cnt;
            cout << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}