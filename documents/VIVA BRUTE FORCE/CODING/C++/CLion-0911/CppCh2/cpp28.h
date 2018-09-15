//따배씨++ 2.8 리터럴 상수 literal constants

#ifndef CLION_0911_CPP28_H
#define CLION_0911_CPP28_H

#include <iostream>

void execFunc() {

    using namespace std;

    float pi = 3.14;   //f가 없으면 double로 캐스팅
    int i = 12323; //캐스팅을 하고 싶다면 12323U 보다는 (unsigned int)로 명확하게 사용.


    unsigned int n = 5u;
    long n2 = 5L;
    double d = 6.0e-10;

    //Decimal : 0 1 2 3 4 5 6 7 8 9 10
    //Octal   : 0 1 2 3 4 5 6 7 10 11 12 13
    //Hexa    : 0 1 2 3 4 5 6 7 8 9 A B C D E F 10

    // 0011 1010 1111
    // 3A7F

    //8진수를 사용하고 싶을 때 맨 앞자리에 0을 사용
    int x = 012;
    cout << x << endl;

    //16진수
    int x1 = 0xF;
    cout << x1 << endl;

    //2진수
    int x2 = 0b1010;
    cout << x2 << endl;


    const int price_per_item = 10;
    int num_items = 123;
    //그냥 * 10을 하고 주석을 적을 수도 있지만, 리터럴 상수를 사용하는 것을 추천.
    int price = num_items * price_per_item;




}


#endif //CLION_0911_CPP28_H
