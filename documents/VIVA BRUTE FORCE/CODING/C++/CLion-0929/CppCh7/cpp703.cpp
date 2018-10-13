
#include <iostream>
#include <cmath>

using namespace std;

// 참조에 의한 인수 전달 Passing Arguments by Reference (Call by Reference)


void addOneCpp703(int &y) {

    cout << y << " " << &y << endl;
    y = y + 1;

}

void cpp7031() {

    int x = 5;


    /*
     *
     *      5 0x7ffee66049dc
            5 0x7ffee66049dc
            6 0x7ffee66049dc

     */
    cout << x << " " << &x << endl;
    addOneCpp703(x);
    cout << x << " " << &x << endl;


}


void getSinCos(const double &degrees, double &sin_out, double &cos_out) {

    // static으로 인해 함수 안에서 매번 초기화 되지 않는다.
    static const double pi = 3.141592 / 180.0;
    const double radians = degrees * pi;
    sin_out = std::sin(radians);
    cos_out = std::cos(radians);

}


void cpp7032() {

    double sin(0.0);
    double cos(0.0);
    getSinCos(30.0, sin, cos);
    cout << sin << " " << cos << endl;

}




/*
 *      int *&ptr 은 (int *) &ptr 로 이해.
 *      즉 int * 에 대한 참조자 레퍼런스.
 *
 *
 *      1) void foo(int *&ptr)
 *      0x7ffee6fae9ec 0x7ffee6fae9e0
 *      0x7ffee6fae9ec 0x7ffee6fae9e0
 *
 *      2) void foo(int *ptr)
 *      0x7ffeef0a69ec 0x7ffeef0a69e0
 *      0x7ffeef0a69ec 0x7ffeef0a69a8
 */

void foo(int *&ptr) {
    cout << ptr << " " << &ptr << endl;
}

void cpp7033() {

    int x = 5;
    int *ptr = &x;

    cout << ptr << " " << &ptr << endl;
    foo(ptr);


}


void printElement(int (&arr)[4]){


}

void cpp7034(){

    int arr[]{1,2,3,4};
    printElement(arr);
}
