#include <iostream>
#include <array>
#include <algorithm>

using namespace std;


/*
 *      void printLength(array<int, 5> my_arr)의 매개변수에서 복사가 일어난다.
 *      자연스럽게 속도를 저하시킨다.
 *
 *      따라서 포인터나 레퍼런스를 사용하면 유용하다. 요소변경을 원하지 않으면 const를 사용한다.
 */
void printLength(const array<int, 5> &my_arr) {
    cout << my_arr.size() << endl;
}

void cpp6201() {

    std::array<int, 5> my_arr = {1, 2, 3, 4, 5};
    my_arr = {0, 1, 2, 3, 4};
    my_arr = {0, 1, 2,};

    cout << my_arr[0] << endl;
    // cout << my_arr.at(0) << endl;    no matching function. why? maybe because of compiler?

    cout << my_arr.size() << endl;
    printLength(my_arr);
}

void cpp6202() {
    std::array<int, 5> my_arr = {1, 21, 3, 40, 5};

    // 레퍼런스 사용으로 속도 향상
    for (auto &element:my_arr)
        cout << element << " ";

    cout << endl;


    std::sort(my_arr.begin(), my_arr.end());

    for (auto &element:my_arr)
        cout << element << " ";

    cout << endl;


    std::sort(my_arr.rbegin(), my_arr.rend());

    for (auto &element:my_arr)
        cout << element << " ";

    cout << endl;

}
