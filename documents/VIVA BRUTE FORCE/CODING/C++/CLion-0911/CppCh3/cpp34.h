//따배씨++ 3.4 sizeof, 쉼표 연산자, 조건부 연산자

#ifndef CLION_0911_CPP34_H
#define CLION_0911_CPP34_H

#include <iostream>

int getPrice(bool onSale) {
    if (onSale)
        return 10;
    else
        return 100;
}

void execFunc() {

    using namespace std;

    float af;
    cout << sizeof(float) << endl;
    cout << sizeof af << endl;
    cout << sizeof(af) << "\n\n" << endl;


    //comma operator

    int x = 3;
    int y = 10;
    int z = (++x, ++y);
    /*
     int z = (++x, ++y);    는
     ++x;
     ++y;
     int z = y;             를 의미.
     */

    cout << x << " " << y << " " << z << endl;

    //z는 1이 출력된다. comma는 =보다 연산자 우선순위가 낮다.
    int a = 1, b = 10;
    z = a++, b++;
    cout << z << "\n\n" << endl;

    //커마 연산자는 지양.


    //conditional operator(arithmetric if)

    bool onSale = true;
    int price = (onSale == true) ? 10 : 100;

//    if (onSale)
//        price = 10;
//    else
//        price = 100;

    cout << price << "\n\n" << endl;

    x = 5;
    cout << ((x % 2 == 0) ? "even" : "odd") << "\n\n" << endl;


}

#endif //CLION_0911_CPP34_H
