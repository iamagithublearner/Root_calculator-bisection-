//bisection method

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double putsValInEq(double value, int a, int b, int c, int d) {
    return (a * (value * value * value)) + (b * (value * value)) + (c * value) + d;
}

vector<double> algo(double x1, double x2, int a, int b, int c, int d, bool flag) {  //returns next roots 
    double avg = (x1 + x2) / 2;
    cout << "--------------------------------" << endl;
    cout << "current x1: " << x1 << " x2: " << x2 << endl;
    cout << "current f(x1): " << putsValInEq(x1, a, b, c, d) << " f(x2): " << putsValInEq(x2, a, b, c, d) << endl;
    cout << "Found avg at " << avg << endl;
    cout << "f(avg): " << putsValInEq(avg, a, b, c, d) << endl;
    vector<double> result;
    flag = false;
    if ((putsValInEq(avg, a, b, c, d) == 0) || (x1 == x2)) {
        result.push_back(x1);
        result.push_back(x2);
        result.push_back(avg);
        flag = true;
        return result;
    }
    else if (signbit(putsValInEq(avg, a, b, c, d)) == (signbit(putsValInEq(x1, a, b, c, d)))) {
        cout << "as the sign of f(x1) and f(avg) are same: " << endl;
        cout << "choosing x1: " << avg << " x2: " << x2 << endl;
        result.push_back(avg);
        result.push_back(x2);
    }
    else {
        cout << "as the sign of f(x2) and f(avg) are same: " << endl;
        cout << "x1: " << x1 << " choosing x2: " << avg << endl;
        result.push_back(x1);
        result.push_back(avg);
    }

    if (flag == false) {
        algo(result.at(0), result.at(1), a, b, c, d, false);
    }
}
int main()
{
    int a, b, c, d = 0;
std:cout << "Enter the values for equation in the form:" << endl << "ax^3 + bx^2 + cx + d " << endl;
    cout << "a" << endl;
    cin >> a;
    cout << "b" << endl;
    cin >> b;
    cout << "c" << endl;
    cin >> c;
    cout << "d" << endl;
    cin >> d;
    cout << "your equation: " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << endl;


    bool preValue, currentValue;
    double initialRootOne = 9999999;
    double initialRootTwo = 9999999;
    cout << "starting initial approximations.. " << endl;
    for (int i = 0; i < 5; i++) {
        float equationValue = putsValInEq(i, a, b, c, d);
        cout << "at " << i << " the value is " << equationValue << endl;
        if (i != 0) {
            currentValue = signbit(equationValue);
            if (currentValue != preValue) {
                cout << "got the values at " << i - 1 << " and " << i << endl;
                initialRootOne = i - 1;
                initialRootTwo = i;
                break;
            }
        }
        if (i == 4) {
            if (initialRootOne == 9999999)
                cout << "initial approximation was not found , please consider increasing the initial approximation values" << endl;
        }
        preValue = signbit(equationValue);
    }
    vector<double> final = algo(initialRootOne, initialRootTwo, a, b, c, d, false);
    cout << "final root is : " << final.at(2);
    return 0;
}