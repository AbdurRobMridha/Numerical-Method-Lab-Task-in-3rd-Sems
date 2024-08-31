#include<bits/stdc++.h>
using namespace std;
vector<double> x;
vector<double> y;
double xi;

double lagrangeIntp() {
    double result = 0.0;
    int n = x.size();

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    x.resize(n);
    y.resize(n);

    cout << "Enter the x values:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the corresponding y values:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    cout << "Enter the value of x to interpolate: ";
    cin >> xi;

    double yi = lagrangeIntp();
    cout << "The interpolated value at x = " << xi << " is y = " << yi << endl;

    return 0;
}

