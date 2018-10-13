#include <iostream>

using namespace std;


void cpp614o() {


    int value = 5;
    int *ptr = &value;
    ptr = &value;

}

void cpp614t() {

    int value = 5;
    int &ref = value;
    cout << ref << endl;

    ref = 10;   // *ptr = 10; 과 같은 효과
    cout << value << " " << ref << endl;

    // & 참조는 별명.
}

void cpp614th() {

    int value = 5;

    int *ptr = nullptr;
    ptr = &value;

    int &ref = value;

    cout << &value << endl; // 0x7ffee42e89bc
    cout << &ref << endl;   // 0x7ffee42e89bc
    cout << ptr << endl;    // 0x7ffee42e89bc
    cout << &ptr << endl;   // 0x7ffee42e89b0

    /*
     *      reference & 는 별명이므로 반드시 생성과 동시에 초기화가 되어야 한다.
     *      그리고 리터럴은 불가.
     *      또 const 변수는 참조할 수 없다.
     *
     */

}

void cpp614f() {

    int value1 = 5;
    int value2 = 10;

    int &ref1 = value1;

    cout << ref1 << endl;
    ref1 = value2;
    cout << ref1 << endl;
}


void doSomething(int n) {
    n = 10;
    cout << "in doSomething " << n << endl;
}

void cpp614fi() {
    int n = 5;

    cout << n << endl;
    doSomething(n);
    cout << n << endl;

}

void doSomething1(int &n) {
    n = 10;
    cout << "in doSomething1 " << n << endl;
}

void cpp614s() {
    int n = 5;

    /*
     *  5
     *  10
     *  10
     */
    cout << n << endl;
    doSomething1(n);
    cout << n << endl;
}

void doSomething2(const int &n) {
    cout << &n << endl;
}


void printElements(int (&arr)[5]) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cpp614se() {
    const int length = 5;
    int arr[length] = {1, 2, 3, 4, 5};


    printElements(arr);
}

struct Something {

    int v1;
    float v2;


};

struct Other {
    Something st;
};


void cpp614e() {
    Other ot;

    int &v1 = ot.st.v1;
    v1 = 1;

    int value = 5;
    int *const ptr = &value;
    int &ref = value;

}

