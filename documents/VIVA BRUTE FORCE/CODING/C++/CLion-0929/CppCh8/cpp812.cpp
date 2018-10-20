#include <iostream>

using namespace std;


class B812; // forward declaration. 불가피한 경우 아니면 지양.

class A812 {
private:
    int m_value = 1;

    friend void doSomething812(A812 &a, B812 &b);


    friend class B812;
};

class B812 {
private:
    int m_value = 2;

    friend void doSomething812(A812 &a, B812 &b);

public:
    void doSomething(A812 &a) {
        cout << a.m_value << endl;
    }
};


void doSomething812(A812 &a, B812 &b) {
    cout << a.m_value << "   " << b.m_value << endl;
}

void cpp812() {

    A812 a;
    B812 b;
    doSomething812(a, b);


}