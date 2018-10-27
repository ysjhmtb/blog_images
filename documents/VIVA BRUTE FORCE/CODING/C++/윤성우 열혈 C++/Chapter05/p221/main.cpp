#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char *name;
    int age;

public:
    Person(const char *myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    // 깊은 복사
    Person(const Person &copy)
            : age(copy.age) {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }


    void showPersonInfo() const {
        cout << "이름 " << name << endl;
        cout << "나이 " << age << endl;
    }

    ~Person() {
        delete[] name;
        cout << "called destructor " << endl;
    }
};

int main() {


    Person man1("Lee dong woo", 29);
    Person man2 = man1;
    man1.showPersonInfo();
    man2.showPersonInfo();


    return 0;
}