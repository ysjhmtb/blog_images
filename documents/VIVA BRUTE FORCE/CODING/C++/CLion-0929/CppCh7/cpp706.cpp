#include <iostream>
#include <array>

using namespace std;


inline int min(int x, int y) {
    return x > y ? y : x;
}

void cpp7061() {


    cout << min(5, 6) << endl;
    cout << min(3, 2) << endl;

}