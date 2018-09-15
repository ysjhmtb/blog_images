//따배씨++ 2.9 심볼릭 상수 symbolic constants

#ifndef CLION_0911_CPP29_H
#define CLION_0911_CPP29_H

#include <iostream>
#include "MY_CONSTANTS.h"

void printNumber(const int my_number) {
    std::cout << my_number << std::endl;
}


void execFunc() {

    using namespace std;

    printNumber(123);
    const double gravity{9.8};


    //컴파일할 때 결정되는 상수를 컴파일 상수.   constexpr
    //실행 후 입력을 받아야 결정되는 상수를 런타임 상수.

    constexpr int my_const(123);

    int number;
    cin >> number;

    const int special_number(number);

    //C에서는 매크로를 사용했지만 C++에서는 아니다.
    int num_item = 123;
    const int price_per_item = 30;
    int price = num_item * price_per_item;


    double radius;
    cin >> radius;
    double circumference = 2.0 * radius * constants::pi;
    cout << circumference << endl;


}


#endif //CLION_0911_CPP29_H
