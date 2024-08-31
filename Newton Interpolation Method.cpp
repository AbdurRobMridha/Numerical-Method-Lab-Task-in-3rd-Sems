#include<bits/stdc++.h>
using namespace std;

vector<double> x;
vector<double> y;
double xi;

double newtonIntp() {
    int n = x.size();
    vector<double> coefficients(n);
    vector<double> divided_diff = y;

    coefficients[0] = divided_diff[0];

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            divided_diff[j] = (divided_diff[j] - divided_diff[j - 1]) / (x[j] - x[j - i]);
        }
        coefficients[i] = divided_diff[i];
    }

    double result = coefficients[0];
    for (int i = 1; i < n; i++) {
        double term = coefficients[i];
        for (int j = 0; j < i; j++) {
            term *= (xi - x[j]);
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

    double yi = newtonIntp();
    cout << "The interpolated value at x = " << xi << " is y = " << yi << endl;

    return 0;
}


