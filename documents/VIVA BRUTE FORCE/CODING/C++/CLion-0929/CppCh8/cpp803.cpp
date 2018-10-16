
#include <iostream>

using namespace std;

class Fraction {

private:
    int m_numerator;
    int m_denominator;

public:


    Fraction(const int &num_in, const int &den_in = 1) {
        m_numerator = num_in;
        m_denominator = den_in;

    }


    void print() {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};


class Second {

public:
    Second() {
        cout << "class Second constructor() " << endl;
    }


};

class First {

    Second sec;

public:
    First() {
        cout << "class First constructor() " << endl;
    }

};


void cpp803() {

    // Fraction one_thirds(1, 3);
    // Fraction one_thirds{1, 3};
    // Fraction one_thirds = Fraction{1, 3};

    /*
     *  Fraction one_thirds(1, 3);  vs  Fraction one_thirds{1, 3};
     *
     *
     *  1) 멤버들이 public이면, 생성자 없이 {1, 3} 초기화 가능.
     *  2) private이면 생성자가 반드시 있어야 한다.
     *  3) {1, 3}는 타입 변환을 허용하지 않는다.
     *  4) 대부분의 경우 비슷하지만 {}이 좀더 엄격함을 요구한다.
     *
     */

    Fraction one_thirds(1, 3);
    one_thirds.print();

    First fir;

}