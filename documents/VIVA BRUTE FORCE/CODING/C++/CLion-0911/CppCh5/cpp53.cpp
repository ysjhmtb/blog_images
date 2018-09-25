#include <iostream>

using namespace std;

enum class Colors {
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE
};


void printColorName(Colors color) {

    switch (color) {
        case Colors::BLACK:
            cout << "Black" << endl;
            break;

        case Colors::RED:
            cout << "Red" << endl;
            break;

        case Colors::BLUE:
            cout << "Blue" << endl;
            break;

        case Colors::WHITE:
            break;

        case Colors::GREEN:
            break;

        default:
            cout << "default" << endl;
            break;
    }


}

void cpp53() {

    printColorName(Colors::BLACK);


}
