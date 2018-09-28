#include <iostream>
#include <cmath>

using namespace std;

void cpp54() {

    double x;

    tryAgain:   //label

    cout << "Enter a non-negative number" << endl;
    cin >> x;

    if (x < 0.0)
        goto tryAgain;

    cout << sqrt(x) << endl;

}
