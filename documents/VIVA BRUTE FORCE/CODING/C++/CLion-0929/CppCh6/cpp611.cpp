#include <iostream>

using namespace std;


void cpp611v1() {

    int array[1000000]; // 오류. 정적으로 할당하는 메모리는 stack으로 들어간다. 그리고 스택은 용량이 작다.
    // 동적으로 할당하는 메모리는 heap으로 들어가고 훨씬 용량이 크다.


}


void cpp611v2() {

    // int var;
    // var = 7;
    // int *ptr = new int;
    // *ptr = 7;

    // 메모리를 할당받으려 하는데, 다른 프로그램이 메모리를 다 사용하고 있어서 못 받을 때가 있다.
    // 이런 경우 메모리를 받을 때까지 버티려면 (std::nothrow)가 필요하다. 예외처리에서 자세히 배운다.
    int *ptr = new(std::nothrow)int{7};

    //0x7fb8d7c00370
    //7

    if (ptr) {
        cout << ptr << endl;
        cout << *ptr << endl;

    } else {
        cout << "Could not allocate memory" << endl;
    }

    delete ptr;
    ptr = nullptr;


    cout << "After delete" << endl;
    if (ptr != nullptr) {
        cout << ptr << endl;
        cout << *ptr << endl;
    }


}

void cpp611v3() {

    int *ptr = new(std::nothrow)int{7};
    int *ptr2 = ptr;

    delete ptr;
    ptr = nullptr;
    ptr2 = nullptr;


    // memory leak

    //    while (true) {
    //        int *ptr = new int;
    //        cout << ptr << endl;
    //    }

            
}


void cpp611() {

    cpp611v3();
}

