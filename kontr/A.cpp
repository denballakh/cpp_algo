#include<iostream>
#include<string>

using namespace std;

#define log(msg) cout << #msg << " ";
#define LOG(msg) cout << #msg << " = " << (msg) << endl;

#define log(...)
#define LOG(...)


int find(int* begin, int* end, int target) {
    int b = *begin;
    int e = *end;
    int* middle = begin + (end - begin) / 2;
    int m = *(middle);
    log(#1)
    if (b == target) return begin - begin + 1;
    if (e == target) return end - begin + 1;
    if (m == target) return middle - begin + 1;
    if (end - begin <= 2) return -1;
    log(#2)
    if ((target - b) * (e - b) < 0) return -1;
    if ((target - e) * (e - b) > 0) return -1;
    log(#3)
    LOG(b)
    LOG(m)
    LOG(e)
    LOG(target)

    if (b < e) {
        log(b#1)
        if (m < target) {
            log(b#1#1)
            int res = find(middle, end, target);
            if (res == -1) return -1;
            log(ok != -1)
            return (middle - begin) + res;
        } else {
            log(b#1#2)
            int res = find(begin, middle, target);
            if (res == -1) return -1;
            log(ok != -1)
            return res;
        }
    } else {
        log(b#2)
        if (m > target) {
            log(b#2#1)
            int res = find(middle, end, target);
            if (res == -1) return -1;
            log(ok != -1)
            return (middle - begin) + res;
        } else {
            log(b#2#2)
            int res = find(begin, middle, target);
            if (res == -1) return -1;
            log(ok != -1)
            return res;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    int* data = new int[n];
    int k;
    cin >> k;
    log(main#1);
    for (int i = 0; i < n; i++)
        cin >> data[i];
    log(main#2);
    cout << find(data, data + n - 1, k) << endl;
    log(main#3)

    delete[] data;
    return 0;
}
