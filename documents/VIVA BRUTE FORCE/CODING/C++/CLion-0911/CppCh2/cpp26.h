

#ifndef CLION_0911_CPP26_H
#define CLION_0911_CPP26_H

#include <iostream>


bool isEqual(int a, int b) {
    bool result = (a == b);

    return result;
}


void execFunc() {

    using namespace std;

    cout << "execFunc() \n" << endl;

    bool b1 = true;     //copy initialization
    bool b2(false);     //direct '''
    bool b3{true};    //uniform ini ...

    b3 = false;

    cout << std::boolalpha; //이 부분을 통해 0과 1이 아닌 false와 true로 출력.
    cout << b3 << endl;
    cout << b1 << "\n" << endl;

    cout << std::noboolalpha;
    cout << !b1 << endl;
    cout << !b2 << "\n" << endl;

    cout << std::boolalpha;
    cout << "&&" << endl;
    cout << (true && true) << endl;
    cout << (true && false) << endl;
    cout << (false || true) << "\n" << endl;

    if (false) {
        cout << "This is true " << "\n" << endl;
    } else {
        cout << "This is false" << "\n" << endl;
    }


    cout << "isEqual : " << endl;
    cout << isEqual(1, 2) << endl;
    cout << endl;


    bool b;

    cin >> b;
    //이때 true와 false로 입력하면 안된다. 1과 0으로 입력해야 한다.
    //애시당초 이런 문제가 발생할 수 있는 선택을 해서는 안 된다.

    cout << std::boolalpha;
    cout << "Your input : " << b << endl;

}


#endif //CLION_0911_CPP26_H
