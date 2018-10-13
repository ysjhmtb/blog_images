#include <iostream>

using namespace std;

struct Person {
    int age;
    double weight;
};

void cpp6161() {

    Person person;
    person.age = 5;
    person.weight = 30;

    Person &ref = person;
    ref.age = 15;


    Person *ptr = &person;
    ptr->age = 30;
    (*ptr).age = 20;    // <- 그런데 이렇게는 잘 사용하지 않는다.

    Person &ref2 = *ptr;
    ref2.age = 45;

    cout << &person << endl;    // 0x7ffee9de19d0
    cout << &ref2 << endl;      // 0x7ffee9de19d0



}