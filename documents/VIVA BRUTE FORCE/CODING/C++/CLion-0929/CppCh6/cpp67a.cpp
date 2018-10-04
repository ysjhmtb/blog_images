#include <iostream>
#include <cstddef>

using namespace std;

void doSomethingCpp67a(double *ptr) {

    cout << "address of pointer variable in doSomething " << &ptr << endl;

    if (ptr != nullptr) {
        // do something useful
        cout << *ptr << endl;
    } else {
        // do something with ptr
        cout << "Null ptr, do nothing " << endl;
    }
}


/*
 *          The error you are getting is because the compiler doesn't recognize the nullptr keyword.
 *          This is because nullptr was introduced in a later version of visual studio
 *          than the one you are using.
 *
 *          https://stackoverflow.com/questions/24433436/compile-error-nullptr-undeclared-identifier
 *
 */
void cpp67a() {

    //double *ptr = 0;    // c style
    // *ptr = NULL;        // c style
    // *ptr = nullptr;     // modern c++ style

    double *ptr{nullptr};

    doSomethingCpp67a(ptr);
    doSomethingCpp67a(nullptr);

    double d = 123.4;
    doSomethingCpp67a(&d);

    ptr = &d;
    doSomethingCpp67a(ptr);

    std::nullptr_t nptr;    // null pointer 전용. 홍정모 교수님도 사용하신 적은 없으시다고 함.

    // 여기서의 &ptr과 매개변수 &ptr은 다르다. 즉, 다른 메모리 사용.
    cout << "address of pointer variable in cpp67a " << &ptr << endl;



}
