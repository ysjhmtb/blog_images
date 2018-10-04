#include <iostream>

using namespace std;


void cpp69v1() {

    int value = 7;
    int *ptr = &value;

    cout << uintptr_t(ptr) << endl; // unsigned integer pointer type
    cout << uintptr_t(ptr + 1) << endl;

}

void cpp69v2() {
    int array[] = {9, 7, 5, 3, 1};

    int *ptr = array;
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " " << (uintptr_t) (ptr + i) << endl;
    }

}


void cpp69v3() {
    char name[] = "Jack Jack";
    const int n_name = sizeof(name) / sizeof(char);
    char *ptr = name;

    for (int i = 0; i < n_name; i++) {
        cout << *(name + i);

    }

    for (int i = 0; i < n_name; i++) {

        cout << *(ptr + i);
    }

    for (int i = 0; i < n_name; i++) {

        if (*(ptr + i) == '\0') {
            break;
        }
        cout << *(ptr + i);
    }
}


void cpp69() {

    cpp69v3();

}