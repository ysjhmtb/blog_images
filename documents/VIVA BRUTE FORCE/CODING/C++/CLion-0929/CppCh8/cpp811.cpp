
#include <iostream>

using namespace std;


class Something811 {

public:
    class _init
    {
    public:
        _init()
        {
            s_value = 9876;
        }
    };


private:
    static int s_value;
    int m_value;

    static _init s_initializer;

public:





    // static 변수는 생성자에서 초기화될 수 없다.
    // static의 의미와 객체의 의미를 생각해 보면 당연하다.

    Something811()
            : m_value(123) {}

    static int getValue() {

        // static 함수에서는 this를 사용할 수 없다.
        return s_value;
    }

    int temp() {

        return this->s_value;
    }
};


int Something811::s_value = 1024;
Something811::_init Something811::s_initializer;


void cpp811() {

    cout << Something811::getValue() << endl;
    Something811 s1, s2;

    cout << s1.getValue() << endl;


    // Something811 클래스에서 객체가 만들어질 때마다 변수는 새로운 메모리에
    // 배정되지만, 함수는 하나의 메모리에만 정해진다.
    // 그래서 &s2::temp 가 아니다.
    int (Something811::*fptr1)() = &Something811::temp;

    cout << (s2.*fptr1)() << endl;


    // static 함수라는 점을 명심하자. Something811::*fptr2 가 아니다.
    int (*fptr2)() = &Something811::getValue;
    cout << fptr2() << endl;


}