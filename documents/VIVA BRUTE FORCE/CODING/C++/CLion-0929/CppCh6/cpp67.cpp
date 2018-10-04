
#include <iostream>
#include <typeinfo>

using namespace std;

struct SomethingCpp67 {
    int a, b, c, d;
};

void cpp67() {

    int x = 5;
    cout << x << endl;
    cout << &x << endl;     // & : address-of operator

    // de-reference operator (*)
    cout << *(&x) << endl;

    cout << "----- ----- ----- ----- ----- ----- " << endl;
    double d = 123.0;

    int *ptr_x = &x;
    double *ptr_d = &d;


    cout << ptr_x << endl;          // 0x7ffedfd24964
    cout << *ptr_x << endl;         // 5

    cout << ptr_d << endl;          // 0x7ffedfd24958
    cout << *ptr_d << endl;         // 123

    cout << typeid(ptr_x).name() << endl;   // Pi = Pointer to integer

    cout << sizeof(x) << endl;      // 4
    cout << sizeof(d) << endl;      // 8
    cout << sizeof(&x) << " " << sizeof(ptr_x) << endl;     // 8 8 : x64의 경우. x86이라면 4일 것.
    cout << sizeof(&d) << " " << sizeof(ptr_d) << endl;     // 8 8


    SomethingCpp67 ss;
    SomethingCpp67 *ptr_s;

    cout << sizeof(SomethingCpp67) << endl; // 16
    cout << sizeof(ptr_s) << endl;          // 8




}
