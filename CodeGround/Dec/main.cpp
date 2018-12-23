
// main.cpp

#include <iostream>
#include <array>

template<class T>
class A {
private:
    T m_value;

public:
    A(const T &input)
            : m_value(input) {}

    template<typename TT>
    void doSomething(const TT &input) {
        std::cout << typeid(T).name() << " " << typeid(TT).name() << std::endl;
        std::cout << (TT) m_value << std::endl;
    }

    void print() {
        std::cout << m_value << std::endl;
    }
};


int main() {


    A<char> a_char('A');
    a_char.print();

    a_char.doSomething<int>(int()); // int() 대신 1 등도 가능.


    return 0;
}