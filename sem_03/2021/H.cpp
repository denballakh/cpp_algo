#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Cat {
    char *name;
    unsigned int id;
    double weight, length;
    unsigned int mice_caught;
};

Cat* get_home_for_a_cats_pride(unsigned int n);
void clear_home_of_a_cats_pride(Cat *cats, unsigned int n);

int main() {
    unsigned int n;
    cin >> n;
    Cat *a = get_home_for_a_cats_pride(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].weight >> a[i].length >> a[i].mice_caught;
        a[i].id = i;
    }
    for (int i = 0; i < n; i++)
        cout << a[i].name << " ";
    cout << endl;
    clear_home_of_a_cats_pride(a, n);
    return 0;
}

#include<string>
// int main_() {
//     unsigned int n;
//     cin >> n;
//     std::string res = "", s;
//     double x;
//     for (int i = 0; i < n; i++) {
//         cin >> s >> x >> x >> x;
//         res += s + " ";
//     }
//     cout << res;
//     return 0;
// }
Cat* get_home_for_a_cats_pride(unsigned int n){
    std::string res = "", s;
    double x;
    for (int i = 0; i < n; i++) {
        cin >> s >> x >> x >> x;
        res += s + " ";
    }
    cout << res;
    return 0;
};
void clear_home_of_a_cats_pride(Cat *cats, unsigned int n){};

Cat* get_home_for_a_cats_pride(unsigned int n) {
    Cat* cats = new Cat[n];
    for (int i = 0; i < n; i++) {
        Cat cat = *(cats + i);
        cat.name = new char[11];
    }
    return cats;
}

void clear_home_of_a_cats_pride(Cat *cats, unsigned int n) {
    for (int i = 0; i < n; i++) {
        Cat cat = *(cats + i);
        delete[] cat.name;
    }
    delete[] cats;
}
