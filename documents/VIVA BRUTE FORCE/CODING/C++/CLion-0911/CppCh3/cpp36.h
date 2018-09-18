

#ifndef CLION_0911_CPP36_H
#define CLION_0911_CPP36_H

#include <iostream>

void execFunc() {
    using namespace std;

    //logical NOT
    bool x = true;
    cout << !x << endl;

    //logical AND
    x = true;
    bool y = false;
    cout << (x && y) << endl;

    //short circuit evaluation
    int xn = 2;
    int yn = 2;
    if (xn == 1 && yn++ == 2) {

        //do something
    }

    //3이 아닌 2
    cout << yn << endl;


    //De Morgan's Law

    x = true;
    y = true;
    cout << !(x || y) << endl;
    cout << (!x && !y) << endl;


    //XOR
    //false false   false
    //false true    true
    //true  false   true
    //true  true    false
    //XOR(a,b) = a'b + ab'

    cout << (x != y) << endl;


}

#endif //CLION_0911_CPP36_H
