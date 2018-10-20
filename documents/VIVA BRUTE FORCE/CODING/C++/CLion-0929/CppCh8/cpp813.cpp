#include <iostream>

using namespace std;


class A813 {
public:

    int m_value;

    A813(const int &input)
            : m_value(input) {
        cout << "Constructor " << endl;
    }

    ~A813() {
        cout << "Destructor " << endl;
    }

    void print() {
        cout << "Hello " << m_value << endl;
    }
};


void cpp813() {

    A813 a(1);
    a.print();

}