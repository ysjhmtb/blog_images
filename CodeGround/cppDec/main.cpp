#include <iostream>

class Something {

public:

    class _init{
    public:
        _init(){
            s_value = 9876;
        }
    };

private:
    // 선언
    static int s_value;
    int m_value;

    // 선언
    static _init s_initializer;

public:


    Something()
            : m_value(123) {}

    static int getValue() {
        return s_value;
    }

    int temp() {
        return this->s_value;
    }
};

// 클래스 내에 선언된 static 변수를 정의. 하지만 아래의 정의에 의해 다시 정의된다.
int Something::s_value = 1024;

// 정의
Something::_init Something::s_initializer;


int main() {

    using namespace std;

    cout << Something::getValue() << endl;

    Something s1, s2;
    cout << s1.getValue() << endl;

    // 멤버함수에 대한 함수 포인터. Something::*fptr1
    // 멤버변수는 객체마다 달리 갖지만, 함수는 하나만 만들어 공유한다.
    int (Something::*fptr1)() = &Something::temp;

    cout << (s2.*fptr1)() << endl;


    // static 함수에 대한 함수 포인터. *fptr2
    int (*fptr2)() = &Something::getValue;

    cout << fptr2() << endl;

    return 0;
}