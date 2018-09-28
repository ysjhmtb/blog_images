#include <iostream>
using namespace std;

void breakOrReturn() {
    while (true) {
        char ch;
        cout << "ch : ";
        cin >> ch;

        if (ch == 'b')
            break;

        if (ch == 'r')
            return;

    }

    cout << "Hello" << endl;
}

void cpp58() {


    int count(0);

    do {
        if (count == 5)
            continue;

        cout << count << endl;

    } while (++count < 10);

}



