#include <iostream>
using namespace std;

class SoSimple {
private:
    int num;

public:
    SoSimple(int n) : num(n) {

    }

    SoSimple &addNum(int n) {
        num += n;
        return *this;
    }

    void simpleFunc() {
        cout << "simpleFunc " << num << endl;
    }

    void simpleFunc() const {
        cout << "const simpleFunc " << num << endl;
    }


};


void yourFunc(const SoSimple &obj){
    obj.simpleFunc();
}

int main() {


    SoSimple obj1(2);
    const SoSimple obj2(7);

    obj1.simpleFunc();
    obj2.simpleFunc();

    yourFunc(obj1);
    yourFunc(obj2);

    return 0;
}