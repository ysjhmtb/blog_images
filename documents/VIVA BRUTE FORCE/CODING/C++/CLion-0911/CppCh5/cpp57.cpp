#include <iostream>

using namespace std;


int pow(int base, int exponent) {
    int result = 1;

    for (int count = 0; count < exponent; count++) {
        result *= base;
    }

    return result;
}

void multiplicationTables() {

    cout << endl;

    for (int i = 2; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
}

void cpp57() {

    for (int count = 0; count < 10; count++) {
        cout << count << endl;
    }


    cout << endl;
    cout << pow(2, 4) << endl;

    cout << endl;
    for (int i = 0, j = 0; i < 10; i++, j--) {
        cout << i << " " << j << endl;
    }

    multiplicationTables();


}