/*
 *  윤성우 열혈 C++ 135page
 *
 *  문자열 정보를 내부에 저장하는 Printer라는 이름의 클래스를 디자인하자.
 *  이 클래스의 두 가지 기능은 다음과 같다.
 *
 *  - 문자열 저장
 *  - 문자열 출력
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Printer {
private:
    string storage;

public:
    void setString(const string &input) {
        storage = input;
    }

    void showString() {
        cout << storage << endl;
    }

};


int main() {

    Printer pnt;
    pnt.setString("Hello world!");
    pnt.showString();


    return 0;
}