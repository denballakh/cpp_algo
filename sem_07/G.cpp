#include<iostream>

// using namespace std;


double f(double x) { return x * x * x - x * x - x - 1; }

double abs(double x) { return x > 0 ? x : -x; }

double find_root(double f(double), double a, double b, double tol) {
    if (a > b) return find_root(f, b, a, tol);
    const double m = (a + b) / 2;
    const double d = (b - a) / 2;
    if (d < tol) return m;
    const double fa = f(a);
    const double fm = f(m);
    const double fb = f(b);
    const double eps = 1e-6;
    if (abs(fm) < eps) return find_root(f, a + d * 0.5, b - d * 0.5, tol);
    if (fa * fm < 0) return find_root(f, a, m, tol);
    else return find_root(f, m, b, tol);
}

int main() {
    std::cout << find_root(f, 1, 3, 0.00000001) << std::endl;

    return 0;
}
