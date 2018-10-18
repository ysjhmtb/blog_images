#include <iostream>

using namespace std;


class B804 {
private:
    int m_b;

public:
    B804(const int &m_b_in)
            : m_b(m_b_in) {


    }
};


class Something804 {

private:
    int m_i;
    double m_d;
    char m_c;
    int m_arr[5];
    B804 m_b;

public:
    Something804()
            : m_i{1}, m_d{3.14}, m_c{'a'}, m_arr{1, 2, 3, 4, 5}, m_b(m_i = 1) {


        m_i *= 3;
        m_d *= 3.0;
        m_c += 3;

    }

    void print() {
        cout << m_i << "    " << m_d << "   " << m_c << endl;
        for (auto &e : m_arr)
            cout << e << " ";
        cout << endl;
    }
};


void cpp804() {

    Something804 som;
    som.print();


}