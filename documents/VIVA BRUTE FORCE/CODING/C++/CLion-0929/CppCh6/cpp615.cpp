#include <iostream>

using namespace std;

void cpp6151() {

    const int x = 5;
    const int &ref_x = x;

    const int &ref_2 = ref_x;

}

void doSomething(const int &x) {

    cout << x << endl;
}


void cpp6152() {

    const int &ref_x = 3 + 4;
    cout << ref_x << endl;
    cout << &ref_x << endl;

    // 매개변수 const int &x 의 장점
    doSomething(5);

}