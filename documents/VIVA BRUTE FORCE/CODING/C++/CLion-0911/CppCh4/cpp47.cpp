
#include <iostream>
#include <typeinfo>
#include <string>


enum Color {

    // user-defined data types

    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_SKYBLUE,
    BLUE,

};


void cpp47() {

    using namespace std;

    // 다음의 세 가지 초기화 방식은 다르다. 추후 강의에서 설명된다.
    Color paint = COLOR_BLACK;
    Color house(COLOR_BLUE);
    Color apple{COLOR_RED};


    Color my_color = COLOR_BLACK;
    cout << my_color << "  " << COLOR_GREEN << endl;

    my_color = static_cast<Color>(3);
    cout << my_color << endl;


     /*

        cin >> my_color  이건 안 된다.



        대신 다음과 같은 방법이 가능하다.

        int in_number;
        cin >> in_number;

        if (in_number == 0) my_color = COLOR_BLACK;
        // ...



        다음과 같은 방법도 가능은 하지만 사용하지 말것.

        string str_input;
        std::getline(cin, str_input);

        if(str_input == "COLOR_BLACK"){

            my_color = static_cast<Color>(0);

        }

      */



}



/*
 *
 *      Switching Compilers
 *
 *      https://www.jetbrains.com/help/clion/how-to-switch-compilers-in-clion.html
 */