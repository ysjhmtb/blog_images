#include <iostream>

using namespace std;


const char *getName() {
    return "JackJack";
}


void cpp610v1() {

    // char name[] = "Jack Jack";
    const char *name = "Jack Jack";     // const 필수.
    const char *name2 = "Jack Jack";


    cout << (uintptr_t) name << endl;   // 4375567342
    cout << (uintptr_t) name2 << endl;  // 4375567342


}


void cpp610v2() {
    int int_arr[5] = {1, 2, 3, 4, 5};
    char char_arr[] = "Hello, World!";
    const char *name = "Jack Jack";

    /*
     *  cout에서 문자열은 특별히 처리한다.
     */
    cout << int_arr << endl;        // 0x7ffee7c829d0
    cout << char_arr << endl;       // Hello, World!
    cout << name << endl;           // Jack Jack


    // &c를 보고 문자열로 파악해서 출력. 널 캐릭터가 나올 때까지 계속 출력.

    char c = 'Q';
    cout << c << endl;              // Q
    cout << &c << endl;             // Q�[
    cout << *&c << endl;            // Q


}


void cpp610() {
    cpp610v2();
}