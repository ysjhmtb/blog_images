

#ifndef CLION_0911_CPP35_H
#define CLION_0911_CPP35_H


#include <iostream>
#include <cmath>


void execFunc() {
    using namespace std;

    int x, y;
    cout << "x, y" << endl;
    cin >> x >> y;
    cout << "x : " << x << ", y : " << y << endl;

    if (x == y)
        cout << "equal" << endl;
    if (x != y)
        cout << "not equal" << endl;
    if (x > y)
        cout << "x is greater than y" << endl;
    if (x < y)
        cout << "x is less than y" << endl;
    if (x >= y)
        cout << "x is greater than y or equal to y" << endl;
    if (x <= y)
        cout << "x is less than or equal to y" << endl;

}


void execFunc1() {
    using namespace std;

    double d1(100 - 99.99);
    double d2(10 - 9.99);


    cout << d1 << endl;
    cout << d2 << endl;
    cout << std::abs(d1 - d2) << endl;

    cout << "\n\n\n" << endl;

    const double epsilon = 1e-10;

    if (d1 == d2)
        cout << "equal" << endl;
    else {

        cout << "not equal" << endl;

        if (d1 > d2)
            cout << "d1 > d2" << endl;
        else
            cout << "d1 < d2" << endl;
    }

    cout << "\n\n\n" << endl;

    if (std::abs(d1 - d2) < epsilon) {
        cout << "Approximately equal" << endl;
    } else {
        cout << "not equal" << endl;
    }


}


#endif //CLION_0911_CPP35_H
