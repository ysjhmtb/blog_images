#include <iostream>
#include <cassert>
#include <array>
#include <iostream>

using namespace std;


void printValue7141(std::array<int, 5> &my_array, const int &ix) {
    assert(ix >= 0);
    assert(ix <= my_array.size() - 1);
    cout << my_array[ix] << endl;
}

void cpp7141() {

    int number = 5;

    assert(number == 5);

    std::array<int, 5> my_array{1, 2, 3, 4, 5};
    // printValue7141(my_array, 100);


}


void cpp7142() {

    const int x = 5;

    // 런 타임에 오류를 발생.
    // x = 10인 경우
    // Assertion failed: (x == 5), function cpp7142, file cpp714.cpp, line 33.
    //Process finished with exit code 6
    assert(x == 5);

    // 컴파일 타임에 오류를 발생시키는 static assert. 컴파일 타임에 변수가 결정되는 경우에만 사용.
    // x = 10인 경우 컴파일을 하면,
    // cpp714.cpp:38:5: error: static_assert failed " x should be 5"
    //    static_assert(x == 5, " x should be 5");
    static_assert(x == 5, " x should be 5");


}


