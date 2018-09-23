

#ifndef CLION_0911_CPP42_H
#define CLION_0911_CPP42_H

#include <iostream>

// forward declaration
extern void doSomethingExternal();


/*
 * internal linkage
 *
 * 개별 cpp 파일 안에서만 전역으로 작동하는 전역변수를 의미.
 * 이 전역변수는 같은 cpp 파일 안에서는 어디서나 접근이 가능하다.
 * 그런데 전역변수에 static을 사용하면 다른 cpp 파일에서는 접근이 불가능하다.
 *
 *
 * external linkage
 *
 *
 *
 */



void doSomething() {
    // used in debugging

    static int a = 1;
    ++a;
    std::cout << a << std::endl;

    /*
     * 메모리가 정적으로 선언된다?
     *
     * 스코프 안에 변수가 선언이 될때, 같은 메모리를 사용하고, 그리고 초기화를 한번만 한다.
     * 만약 doSomething()이 여러번 실행이 된다면 매번 다른 메모리에 a를 할당하는 것이
     * 아니라 같은 메모리를 사용한다는 의미.
     *
     * 전역변수를 사용해도 static과 같은 결과를 만들어 낼 수 있다. 하지만 static과 달리
     * 전역변수는 더 광범위한 스코프에서 접근이 가능하고 따라서 그만큼 위험이 증가한다.
     */
}




// 전역변수
int value = 123;



void execFunc() {

    using namespace std;


    // external
    doSomethingExternal();

    // 2
    doSomething();
    // 3, because of static
    doSomething();



    // 123
    cout << "Global variable : " << value << endl;

    // 지역변수
    int value = 1;

    // 123
    cout << ::value << endl;

    // 1
    cout << "Local variable : " << value << endl;


}


#endif //CLION_0911_CPP42_H
