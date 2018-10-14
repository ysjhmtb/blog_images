#include <iostream>
#include <string>
#include <array>
#include <functional>

using namespace std;

// 함수 포인터

int func7091() {

    return 5;
}

int funct7091(int x) {
    return x;
}

int goo7091() {
    return 10;
}

void cpp7091() {

    // 함수 포인터
    int (*fcnptr)() = func7091;
    cout << fcnptr() << endl;   // 5

    fcnptr = goo7091;
    cout << fcnptr() << endl;   // 10

    int (*fptr2)(int) = funct7091;
    cout << fptr2(3) << endl;   // 3

}


bool isEven(const int &number) {
    if (number % 2 == 0)
        return true;
    else
        return false;
}

bool isOdd(const int &number) {
    if (number % 2 != 0)
        return true;
    else
        return false;
}

/*
 *      typedef bool(*check_fcn_t)(const int &);    혹은
 *      using check_fct_t = bool(*)(const int &);
 *
 *      check_fcn_t check_fcn = isEven 으로 가능.
 */

void printNumbers7092(const array<int, 10> &my_array,
                      bool (*check_fcn)(const int &) = isEven) {

    for (auto element:my_array) {
        if (check_fcn(element) == true) cout << element << " ";
    }
    cout << endl;

}

void cpp7092() {

    std::array<int, 10> my_array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printNumbers7092(my_array, isOdd);
    printNumbers7092(my_array);


}