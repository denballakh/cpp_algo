#include<iostream>

using namespace std;

int main() {
    char h1, h2, m1, m2, s1, s2, temp;
    int time1, time2;
    int h, m, s;
    int result;

    cin >> h1 >> h2 >> temp >> m1 >> m2 >> temp >> s1 >> s2;
    h = (h2 - '0') + (h1 - '0') * 10;
    m = (m2 - '0') + (m1 - '0') * 10;
    s = (s2 - '0') + (s1 - '0') * 10;
    time1 = h * 3600 + m * 60 + s;

    cin >> h1 >> h2 >> temp >> m1 >> m2 >> temp >> s1 >> s2;
    h = (h2 - '0') + (h1 - '0') * 10;
    m = (m2 - '0') + (m1 - '0') * 10;
    s = (s2 - '0') + (s1 - '0') * 10;
    time2 = h * 3600 + m * 60 + s;

    result = time2 - time1;
    if(result < 0) result += 24 * 3600;
    cout << result << endl;

    return 0;
}