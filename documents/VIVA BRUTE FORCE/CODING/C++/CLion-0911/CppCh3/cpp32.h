//따배씨++ 3.2 산술 연산자 arithmetic operators

#ifndef CLION_0911_CPP32_H
#define CLION_0911_CPP32_H

#include <iostream>


void execFunc() {
    using namespace std;

    int x = 1;
    int y = 1 - -x;

    cout << "1 - -x = " << y << endl;

    int x1 = 7;
    int y1 = 4;
    int z1 = x1 % y1;
    cout << "\n x1 / y1 = " << x1 / y1 << ", x1 % y1 = " << z1 << endl;
    cout << "\n float(x1) / y1  = " << float(x1) / y1 << endl;
    cout << "x1 / float(y1) = " << x1 / float(y1) << endl;
    cout << "float(x1) / float(y1) = " << float(x1) / float(y1) << endl;

    cout << "\n\n -5 / 2 = " << -5 / 2 << endl;
    cout << "-5 % 2 = " << -5 % 2 << endl;

    z1 = x1;
    z1 += y1;    // z1 = z1 + y1





}


#endif //CLION_0911_CPP32_H
