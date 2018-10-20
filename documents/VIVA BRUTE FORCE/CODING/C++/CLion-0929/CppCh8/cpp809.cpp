
#include <iostream>

using namespace std;


class Something809 {
public:
    int m_value = 0;

    // 복사 생성자가 숨어있다.

    void setValue(int value) { m_value = value; };

    // m_value의 값이 변경되지 않는 것을 명시. const인 변수가 이 메소드를 사용하려면 필요.
    int getValue() const {
        return m_value;
    }
};


void print(Something809 st) {
    cout << &st << endl;

    cout << st.m_value << endl;
}

void cpp809() {

    Something809 something;

    cout << &something << endl;
    print(something);


}