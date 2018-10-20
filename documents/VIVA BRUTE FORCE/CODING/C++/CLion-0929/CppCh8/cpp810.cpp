
#include <iostream>

using namespace std;

class Something810 {
public:
    int m_value = 1;

};

// static 변수는 h가 아닌 cpp 파일에 있어야 한다!!!

void cpp810() {
    Something810 st1;
    Something810 st2;

    st1.m_value = 2;

    // 두 변수의 주소가 다르다. static 변수라면 주소가 같다.
    cout << &st1.m_value << "   " << st1.m_value << endl;
    cout << &st2.m_value << "   " << st2.m_value << endl;
}

