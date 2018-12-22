
// main.cpp

#include <iostream>


class Mother {
private:
    int m_i;

public:
    Mother(const int &i_in = 0) : m_i(i_in) {
        std::cout << "Mother construction" << std::endl;
    }
};

class Child : public Mother {
private:
    double m_d;

public:
    Child() : Mother(1024), m_d(1.0) {
        std::cout << "Child construction" << std::endl;
    }
};

class A {
public:
    A() {
        std::cout << "A constructor " << std::endl;
    }
};

class B : public A {
public:
    B() {
        std::cout << "B constructor " << std::endl;
    }
};


class C : public B {
public:
    C() {
        std::cout << "C constructor " << std::endl;
    }
};


int main() {


//    Mother construction
//    Child construction
    Child c1;

//    A constructor
//    B constructor
//    C constructor
    C c;


    return 0;
}
