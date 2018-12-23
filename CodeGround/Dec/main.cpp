
// main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;


class Base {
public:
    Base() {};

    // friend function은 멤버가 아니다. 따라서 오버라이딩을 할 수가 없다.
    friend std::ostream &operator<<(std::ostream &out, const Base &b) {
        return b.print(out);
    }

    virtual std::ostream &print(std::ostream &out) const {
        out << "Base";
        return out;
    }

};


class Derived : public Base {
public:
    Derived() {}

    virtual std::ostream &print(std::ostream &out) const override {
        out << "Derived";
        return out;
    }
};


int main() {

    Base b;
    std::cout << b << std::endl;

    Derived d;
    std::cout << d << std::endl;

    Base &bref = d;
    std::cout << bref << std::endl;


    return 0;
}
