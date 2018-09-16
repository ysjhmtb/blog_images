//따배씨++ 3.3 증가/감소 (증감) 연산자 increment/decrement operators

#ifndef CLION_0911_CPP33_H
#define CLION_0911_CPP33_H

#include <iostream>

int add(int a, int b) {
    std::cout << "a : " << a << " b : " << b << std::endl;
    return a + b;
}

void execFunc() {
    using namespace std;

    int x = 5;
    int y = ++x;
    int z = x--;


    x = 6, y = 6;
    cout << x++ << " " << y-- << endl;
    cout << x << " " << y << endl;

    /*

     warning: unsequenced modification and access to 'x'

    x = 1;
    int v = add(x, ++x);
    cout << v << endl;

     https://stackoverflow.com/questions/33743254/c-unsequenced-modification-and-access-to-i

     */

    x = 1;
    y = ++x;
    int v = add(x, y);  // do not use.
    cout << v << endl;

    /*

    x = 1;
    x = x++;
    cout << x << endl;

     warning: multiple unsequenced modifications to 'x'

     즉 이렇게 작성하지 말라.
     */

}

#endif //CLION_0911_CPP33_H
