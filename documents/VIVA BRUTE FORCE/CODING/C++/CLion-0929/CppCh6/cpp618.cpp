#include <iostream>

using namespace std;


void cpp6181() {

    // void pointer, generic pointer

    int i = 5;
    float f = 3.0;
    char c = 'a';

    void *ptr = nullptr;

    ptr = &i;
    ptr = &f;
    // ptr = &c;

    int *ptr_i = &i;

    // 0x7ffee01129e8 0x7ffee01129e8
    cout << &f << " " << ptr << endl;

    // 3
    cout << *static_cast<float *>(ptr) << endl;


}