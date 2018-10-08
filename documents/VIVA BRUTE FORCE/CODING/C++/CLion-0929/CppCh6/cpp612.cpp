#include <iostream>

using namespace std;

void cpp612() {

    int length;

    cin >> length;
    int *array = new int[length];

    array[0] = 1;
    array[1] = 2;

    for (int i = 0; i < length; i++) {
        cout << (uintptr_t) &array[i] << endl;
        cout << array[i] << endl;

    }

    delete[] array;
    /*
     *  3
     *
     *  140189087302512
     *  1
     *  140189087302516
     *  2
     *  140189087302520
     *  0
     */


}

void cpp612v1() {
    int fixedArray[] = {1, 2, 3, 4, 5};
    int *array = new int[3]{1, 2, 3};


    // resizing





    delete[] array;


}
