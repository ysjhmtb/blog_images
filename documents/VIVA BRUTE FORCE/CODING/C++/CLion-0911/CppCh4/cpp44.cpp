
#include <iostream>


int add(int x, int y) {
    return x + y;
}

void cpp44() {

    using namespace std;

    // 자료형 추론
    auto a = 123;
    auto b = 123.0;
    auto c = 1 + 2.0;


    auto result = add(1, 2);
    cout << result << endl;



}

