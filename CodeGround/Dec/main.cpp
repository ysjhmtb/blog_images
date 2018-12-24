
// main.cpp

#include <iostream>
#include <memory>


class A {
public:
    ~A() {
        // throw "error";  // 소멸자 안에서의 throw는 금기시된다.
    }
};

int main() {

    try {
        int *i = new int[10000];
        // std::unique_ptr<int> up_i(i);   // unique_ptr을 사용하면 delete가 필요하지 않다.

        throw "error";
        delete[] i;     // memory leak!

    } catch (...) {
        std::cout << "Catch" << std::endl;
    }



    try {
        A a;


    } catch (...) {
        std::cout << "Catch" << std::endl;
    }


}
