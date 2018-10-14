#include <iostream>
#include <vector>

using namespace std;


void countDown712(int count) {

    if (count < 0)
        return;

    cout << count << endl;
    countDown712(count - 1);
}

void cpp7121() {

    countDown712(5);

}