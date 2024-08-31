#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x - 3*x + 2;
}

double f_prime(double x) {
    return 2*x -3;
}

double newtonRaphson(double x0, double tol) {
    double x1;
    while (true) {
        x1 = x0 - f(x0) / f_prime(x0);
        if (fabs(x1 - x0) < tol)
            break;
        x0 = x1;
    }
    return x1;
}

int main() {
    double x0, tol;
    cout << "Enter the initial guess x0: ";
    cin >> x0;
    cout << "Enter the tolerance level: ";
    cin >> tol;

    double root = newtonRaphson(x0, tol);
    cout << "The root is: " << root << endl;
    return 0;
}

