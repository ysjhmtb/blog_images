
#include <iostream>

using namespace std;

// 값에 의한 전달 Passing Arguments by Value (Call by Value)


void doSomethingCpp702(int y) {
    cout << "in func " << y << "  " << &y << endl;
}

void cpp7021() {

    doSomethingCpp702(5);

    int x = 6;

    /*
     *      in func 5   0x7ffeedcb29bc
            in main 6   0x7ffeedcb29ec
            in func 6   0x7ffeedcb29bc
            in func 7   0x7ffeedcb29bc



            0x7ffeedcb29bc      vs     0x7ffeedcb29ec

     */
    cout << "in main " << x << " " << &x << endl;
    doSomethingCpp702(x);
    doSomethingCpp702(x + 1);
}
