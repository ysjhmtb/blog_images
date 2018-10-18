#include <iostream>

using namespace std;

// 생성자가 다른 생성자를 사용하는 것을 위임 생성자 Delegating Constructors라 한다.


class Student805 {
private:
    int mid;
    string mname;

public:

    Student805(const string &name_in)
            : Student805(0, name_in) {}

    Student805(const int &id_in, const string &name_in)
            : mid(id_in), mname(name_in) {}

    void print() {
        cout << mid << "    " << mname << endl;
    }

};


void cpp805() {

    Student805 st1(0, "Jack Jack");
    st1.print();

    Student805 st2("Dash");
    st2.print();


}