

// 따배씨++ 4.1 지역 변수, 범위, 지속기간

#ifndef CLION_0911_CPP41_H
#define CLION_0911_CPP41_H

#include <iostream>

namespace work1 {

    int a = 1;

    void doSomething() {
        a += 3;
    }

    namespace work11 {
        void print11() {
            std::cout << "namespace work11" << std::endl;
        }
    }
}


namespace work2 {
    int a = 1;

    void doSomething() {
        a += 5;
    }
}

void execFunc() {


    using namespace std;

    // 변수 apple은 이 라인 이하에서 이 스코프 내에서만 사용될 수 있다.
    int apple = 5;

    cout << apple << endl;


    {
        int apple = 1;
        cout << apple << endl;
    }


    cout << apple << endl;


    // namespace
    work1::work11::print11();

    work1::doSomething();
    cout << work1::a << endl;

    work2::doSomething();
    cout << work1::a << endl;


}


#endif //CLION_0911_CPP41_H
