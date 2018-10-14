#include <iostream>
#include <string>

using namespace std;


void print7081(int x = 10, int y = 20, int z = 30) {
    cout << x << "  " << y << " " << z << endl;
}



void cpp7081() {


    print7081();
    print7081(100);
    print7081(100, 200);
    print7081(100, 200, 300);

}