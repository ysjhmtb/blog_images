#include <iostream>

using namespace std;


struct Person {

    double height;
    float weight;
    int age;
    string name;

    void print() {
        cout << height << " " << weight << " " << age << " " << name;
        cout << endl;
    }
};


Person getMe() {
    Person me{2.0, 100.0, 20, "Jack Jack"};
    return me;
}


struct Employee {

    // 2 + (2) + 4 + 8 = 16     padding

    short id;     // 2 bytes
    int age;    // 4 bytes
    double wage;   // 8 bytes
};

void cpp410() {

    Person me2(getMe());
    me2.print();


    cout << sizeof(Employee) << endl;


}