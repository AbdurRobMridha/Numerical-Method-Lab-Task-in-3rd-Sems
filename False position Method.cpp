#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x  - x - 2;
}

double falsePosition(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval." << endl;
        return -1;
    }

    double c = a;
    while (fabs(f(c)) > tol) {
        c = b - (f(b) * (b - a)) / (f(b) - f(a));

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

    double root = falsePosition(a, b, tol);
    if (root != -1)
        cout << "The root is: " << root << endl;
    return 0;
}

