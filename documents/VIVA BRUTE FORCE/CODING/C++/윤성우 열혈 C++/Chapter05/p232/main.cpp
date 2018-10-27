#include <iostream>

using namespace std;

class SoSimple {
private:
    int num;

public:
    SoSimple(int n) : num(n) {

    }

    SoSimple(const SoSimple &copy)
            : num(copy.num) {
        cout << "called SoSimple(const SoSimple &copy) " << endl;
    }

    SoSimple &addNum(int n) {
        num += n;
        return *this;
    }

    void showData() {
        cout << "num : " << num << endl;
    }

};

SoSimple simpleFuncObj(SoSimple ob) {
    cout << "return 이전 " << endl;
    return ob;
}

int main() {


    /*
     *  called SoSimple(const SoSimple &copy)
        return 이전
        called SoSimple(const SoSimple &copy)
        num : 37
        num : 7
     */


    SoSimple obj(7);
    simpleFuncObj(obj).addNum(30).showData();
    obj.showData();

    return 0;
}