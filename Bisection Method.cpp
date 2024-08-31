#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x  -4* x - 10;
}

double bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval." << endl;
        return -1;
    }

    double c = a;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    double a, b, tol;
    cout << "Enter the initial guess a: ";
    cin >> a;
    cout << "Enter the initial guess b: ";
    cin >> b;
    cout << "Enter the tolerance level: ";
    cin >> tol;

    double root = bisection(a, b, tol);
    if (root != -1)
        cout << "The root is: " << root << endl;
    return 0;
}
