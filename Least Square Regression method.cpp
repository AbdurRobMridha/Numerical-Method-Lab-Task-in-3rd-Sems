#include<bits/stdc++.h>
using namespace std;
vector<double> x, y;
double b0, b1;

double mean(const vector<double>& v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double covariance(double x_mean, double y_mean) {
    double covar = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        covar += (x[i] - x_mean) * (y[i] - y_mean);
    }
    return covar;
}

double variance(double x_mean) {
    double var = 0.0;
    for (double xi : x) {
        var += (xi - x_mean) * (xi - x_mean);
    }
    return var;
}

void least_squares() {
    double x_mean = mean(x);
    double y_mean = mean(y);
    b1 = covariance(x_mean, y_mean) / variance(x_mean);
    b0 = y_mean - b1 * x_mean;
}

double predict(double x_value) {
    return b0 + b1 * x_value;
}

void input_data() {
    int n;
    cout<<"Enter the number of data points:";
    cin>>n;

    x.resize(n);
    y.resize(n);

    cout<<"Enter x values:";
    for (int i = 0; i < n; ++i) {
        cin>>x[i];
    }

    cout<<"Enter y values:";
    for (int i = 0; i < n; ++i) {
        cin>>y[i];
    }
}
int main() {
    input_data();
    least_squares();

   // cout<<"Results:\n";
    cout<< "a: "<<b0<<endl;
    cout<< "b: "<<b1<<endl;
    cout<<"Equation: y = "<<b0<<" + "<<b1<<"x\n";

    char choice;
    cout<<"Would you like to make a prediction? (y/n):";
    cin>>choice;

    if(choice == 'y' || choice == 'Y') {
        double x_value;
        cout<<"Enter x value for prediction:";
        cin>>x_value;
        double predicted_y = predict(x_value);
        cout<<"For x = "<<x_value<<", Predicted y = "<<predicted_y<<endl;
    }

    return 0;
}


