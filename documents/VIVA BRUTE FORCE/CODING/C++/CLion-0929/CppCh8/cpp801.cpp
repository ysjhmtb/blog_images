#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Friend801 {

public:
    string name;
    string address;
    int age;
    double height;
    double weight;

    void print() {
        cout << name << "   " << address << "   " << age << "   " << height << "    " << weight << endl;
    }
};


void cpp801() {

    vector<Friend801> my_friends;
    my_friends.resize(2);



}