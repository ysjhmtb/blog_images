#include "Calc807.h"

using namespace std;

Calc807::Calc807(int init_value)
        : m_value(init_value) {

}

Calc807 &Calc807::add(int value) {
    m_value += value;
    return *this;
}

Calc807 &Calc807::sub(int value) {
    m_value -= value;
    return *this;
}

Calc807 &Calc807::mul(int value) {
    m_value *= value;
    return *this;
}

void Calc807::print() {

    cout << m_value << endl;
}