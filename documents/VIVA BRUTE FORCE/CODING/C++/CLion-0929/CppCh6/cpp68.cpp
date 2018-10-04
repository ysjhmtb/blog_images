#include <iostream>

using namespace std;

void cpp68v1() {
    int array[5] = {9, 7, 5, 3, 1};
    cout << array[0] << " " << array[1] << endl;    // 9 7
    cout << array << endl;                          // 0x7ffeeeddd9d0
    cout << &array[0] << endl;                      // 0x7ffeeeddd9d0

    cout << *array << endl;                         // 9

    int *ptr = array;
    cout << ptr << endl;                            // 0x7ffee514a9d0
    cout << *ptr << endl;                           // 9
    cout << &ptr << endl;                           // 0x7ffee5a30938

    char name[] = "jackjack";
    cout << *name << endl;                          // j

}


void printArrCpp68(int array[]) {

    // int array[] == int *array
    // 따라서 배열처럼 보이지만 내부적으로 포인터로 동작한다.
    // cout << sizeof(array) << endl;
    cout << *array << endl;

    *array = 100;
}

void cpp68v2() {

    int array[5] = {9, 7, 5, 3, 1};
    cout << sizeof(array) << endl;      // 20
    int *ptr = array;
    cout << sizeof(ptr) << endl;        // 8

    printArrCpp68(array);               // 8
    // 9

    cout << array[0] << " " << *array << endl;  // 100 100


    cout << *ptr << " " << *(ptr + 1) << endl;  // 100 7

}


struct MyStructCpp68 {
    int array[5] = {9, 7, 5, 3, 1};

};

void doSomethingCpp68(MyStructCpp68 ms) {

    /*
     *  (MyStructCpp68 ms)  대신 (MyStructCpp68 *ms)
     *
     *  cout << sizeof(ms.array) << endl;   대신
     *  cout << sizeof((*ms).array) << endl;
     *
     *  doSomethingCpp68(ms); 대신
     *  doSomethingCpp68(&ms);
     *
     *  를 해도 결과는 같다.
     */
    cout << sizeof(ms.array) << endl;
}

void cpp68v3() {
    MyStructCpp68 ms;
    cout << ms.array[0] << endl;            // 9
    cout << sizeof(ms.array) << endl;       // 20
    doSomethingCpp68(ms);                   // 20

}

void cpp68() {
    cpp68v3();
}