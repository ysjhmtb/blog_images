#include <iostream>

using namespace std;


int getInt() {


    while (true) {
        cout << "Enter an integer number : ";
        int x;
        cin >> x;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            cout << "invalid number" << endl;
        } else {
            std::cin.ignore(32767, '\n');
            return x;
        }
    }


}


char getOperator() {


    while (true) {

        cout << "Enter an operator (+,-) : ";
        char op;
        cin >> op;
        std::cin.ignore(32767, '\n');

        if (op == '+' || op == '-')
            return op;

    }
}

void printResult(int x, char op, int y) {
    if (op == '+') cout << x + y << endl;
    else if (op == '-') cout << x - y << endl;
    else {
        cout << "invalid operator" << endl;
    }
}

void cpp510() {

    int x = getInt();
    char op = getOperator();
    int y = getInt();

    printResult(x, op, y);
}

