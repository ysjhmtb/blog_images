#include <iostream>
#include <array>
#include <tuple>

using namespace std;

int getValue7051(int x) {
    int value = x * 2;
    return value;
}

/*
 * warning: address of stack memory associated
 * with local variable 'value' returned [-Wreturn-stack-address]
 *
 *
        int *getValue7051p(int x) {
            int value = x + 2;
            return &value;
        }
*/


int *allocateMemory(int size) {
    return new int[size];
}

void cpp7051() {

    int value = getValue7051(3);

    int *array = allocateMemory(1024);
    delete[] array; // 이처럼 생성과 소멸을 별개로 해야 하므로 불편하다.



}


int &get7052(std::array<int, 100> &my_array, int ix) {

    return my_array[ix];
}


std::tuple<int, double> getTuple7052() {
    int a = 10;
    double d = 3.14;
    return std::make_tuple(a, d);

};


void cpp7052() {

    std::array<int, 100> my_array;
    my_array[30] = 10;

    get7052(my_array, 30) = 1024;

    cout << my_array[30] << endl;


    auto[a, d] = getTuple7052();
    cout << a << endl;
    cout << d << endl;

}