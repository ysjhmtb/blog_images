#include <iostream>

using namespace std;


void cpp613v1() {

    const int value = 5;
    const int *ptr = &value;
//     *ptr = 6;    const 이므로 불가
    cout << *ptr << endl;


}

void cpp613v2() {

    int value = 5;
    const int *ptr = &value;

    // *ptr = 6; 은 안되지만, value = 6은 된다.
    value = 6;
    cout << *ptr << endl;
}


void cpp613v3() {

    int value1 = 5;
    const int *ptr = &value1;

    int value2 = 6;

    // 된다!!! int * 앞에 const를 붙이는 것은
    // '가리키고 있는 주소에 있는 값'을 변경하지 않겠다는 것이지
    // 'ptr에 저장되는 주소값'을 변경하지 않겠다는 의미가 아니다.
    ptr = &value2;


}


/*
 *  const int *ptr  vs  int *const ptr
 *
 *  1) const (int *)
 *  2) (int *) const
 *
 */

void cpp613v4() {

    int value = 5;
    int *const ptr = &value;

    *ptr = 10;
    cout << *ptr << endl;

    int value2 = 8;
    // ptr = &value2; 불가!

}

void cpp613v5() {

    int value = 5;
    const int *const ptr = &value;


}


void cpp613v6() {

    int value = 5;
    const int *ptr1 = &value;
    int *const ptr2 = &value;
    const int *const ptr3 = &value;

}
