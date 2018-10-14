#include <iostream>

using namespace std;

// 주소에 의한 인수 전달 Passing Arguments by Address(Call by Address)


void fooCpp7041(int *ptr) {

    cout << *ptr << "   " << ptr << "   " << &ptr << endl;

}

void fooReCpp7041(int *&ptr) {

    cout << *ptr << "   " << ptr << "   " << &ptr << endl;

}

void foo2Cpp7041(const double degrees, double *sin_out, double *cos_out) {
    *sin_out = 1.0;
    *cos_out = 2.0;
}

void cpp7041() {

    int value = 5;
    cout << value << "  " << &value << endl;

    int *ptr = &value;

    fooCpp7041(ptr);
    fooCpp7041(&value);
    fooReCpp7041(ptr);

    double degrees = 30;
    double sin, cos;

    foo2Cpp7041(degrees, &sin, &cos);
    cout << sin << "    " << cos << endl;


}



