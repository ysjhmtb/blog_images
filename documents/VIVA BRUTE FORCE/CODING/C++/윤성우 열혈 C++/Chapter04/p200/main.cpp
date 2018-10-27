#include <iostream>

using namespace std;

class SelfRef {

private:
    int num;


public:
    SelfRef(int n) : num(n) {
        cout << "객체 생성 " << endl;
    }

    SelfRef &adder(int n) {
        num += n;
        return *this;
    }

    SelfRef &showTwoNumber() {
        cout << num << endl;
        return *this;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    SelfRef obj(3);
    SelfRef &ref = obj.adder(2);

    obj.showTwoNumber();
    ref.showTwoNumber();

    ref.adder(1).showTwoNumber().adder(2).showTwoNumber();

    return 0;
}