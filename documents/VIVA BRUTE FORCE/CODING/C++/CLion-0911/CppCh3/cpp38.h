//따배씨++ 3.8 비트단위 연산자 Bitwise Operators

#ifndef CLION_0911_CPP38_H
#define CLION_0911_CPP38_H

#include <iostream>
#include <bitset>

void execFunc() {

    using namespace std;

    //  <<  left shift
    //  >>  right shift
    //  ~  , & , | , ^

    //bitwise operator에서는 unsigned가 원칙.
    unsigned int a = 1;

    // bitset을 사용하면 정수를 이진수로 볼 수 있다.
    // 0001
    cout << bitset<4>(a) << endl;

    unsigned int b = a << 1;
    // 0010
    // 왜냐하면 0001이 1비트 왼쪽으로 이동.
    cout << bitset<4>(b) << endl;




    // left shift
    //
    // 0000 0001
    // 0000 0010    2
    // 0000 0100    4
    // 0000 1000    8
    // 0001 0000    16
    cout << bitset<8>(a) << endl;
    cout << bitset<8>(a << 1) << " " << (a << 1) << endl;
    cout << bitset<8>(a << 2) << " " << (a << 2) << endl;
    cout << bitset<8>(a << 3) << " " << (a << 3) << endl;
    cout << bitset<8>(a << 4) << " " << (a << 4) << endl;




    // right shift
    a = 1024;


    /*
     * 0000 0100 0000 0000
     * 0000 0010 0000 0000 512
     * 0000 0001 0000 0000 256
     * 0000 0000 1000 0000 128
     * 0000 0000 0100 0000 64
     *
     */
    cout << bitset<16>(a) << endl;
    cout << bitset<16>(a >> 1) << " " << (a >> 1) << endl;
    cout << bitset<16>(a >> 2) << " " << (a >> 2) << endl;
    cout << bitset<16>(a >> 3) << " " << (a >> 3) << endl;
    cout << bitset<16>(a >> 4) << " " << (a >> 4) << endl;





    //bitwise not

    // ! : logical not
    // ~ : bitwise not

    // 0000 0100 0000 0000
    // 1111 1011 1111 1111  4294966271
    // 0000 0000 0000 0000  0

    a = 1024;
    cout << bitset<16>(a) << endl;
    cout << bitset<16>(~a) << " " << (~a) << endl;
    cout << bitset<16>(!a) << " " << (!a) << endl;


    a = 0b1100;
    b = 0b0110;

    /*
     * 12   6
     * bitwise AND  0100
     * bitwise OR   1110
     * bitwise XOR  1010
     *
     */
    cout << a << "      " << b << endl;
    cout << bitset<4>(a & b) << endl;
    cout << bitset<4>(a | b) << endl;
    cout << bitset<4>(a ^ b) << endl;

    a &= b;


    /*
     * Quiz
     *
     * 0110 >> 2 -> decimal
     * 5 | 12
     * 5 & 12
     * 5 ^ 12
     */

    cout << (0b0110 >> 2) << endl;
    cout << (5 | 12) << endl;
    cout << (5 & 12) << endl;
    cout << (5 ^ 12) << endl;

}

#endif //CLION_0911_CPP38_H
