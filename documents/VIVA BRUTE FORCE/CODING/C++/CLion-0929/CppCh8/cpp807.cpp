#include <iostream>
#include "Calc807.h"

using namespace std;

class Simple807 {
private:
    int m_id;

public:
    Simple807(int id) {
        setID(id);

        cout << this->m_id << endl;

        // VS와 달리 CLion에서는 안된다.
        // cout < this << endl;
    }

    void setID(int id) { m_id = id; };

    int getID() { return m_id; };
};



void cpp807() {

    Simple807 s1(1), s2(2);
    s1.setID(2);
    s2.setID(4);

    cout << &s1 << "  " << &s2 << endl;

    Calc807 cal(10);
    cal.add(10).sub(1).mul(2).print();


}
