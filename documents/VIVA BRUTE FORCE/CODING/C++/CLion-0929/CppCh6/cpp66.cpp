#include <iostream>
#include <cstring>

using namespace std;

void cpp66() {

    //C언어 스타일

    char myString[] = "string";

    /*
     *  115
        116
        114
        105
        110
        103
        0

     */
    for (int i = 0; i < 7; ++i) {
        cout << (int) myString[i] << endl;
    }

    // 7
    cout << sizeof(myString) / sizeof(myString[0]) << endl;


    /*
     *      char cinStr[255];
            cout << "입력 : " << endl;
            cin >> cinStr;
            cinStr[4] = '\0';   // null character
            cout << cinStr << endl;
     *
     *
     *      입력을 HelloJack이라고 넣어도
     *      출력은 Hell만 나온다. cinStr[4] = '\0'; 때문이다.
     */



    /*
     *
     *      입력 :
            Jack Hello

            Jack Hello

            J 74
            a 97
            c 99
            k 107
              32
            H 72
            e 101
            l 108
            l 108
            o 111


            1) 빈칸의 ASCII는 32.
            2) null(\0)과 빈칸(32)은 다르다.
     */


    char cinStr[255];


    cout << "입력 : " << endl;
    cin.getline(cinStr, 255);
    cout << cinStr;

    int ix = 0;
    while (true) {
        if (cinStr[ix] == '\0') break;
        cout << cinStr[ix] << " " << (int) cinStr[ix] << endl;
        ++ix;
    }


}


void cpp66v2() {

    /*
     *  다음과 같은 방법은 위험하다.
     *  만약에 dest의 길이가 충분하지 않다면 런타임 에러가 발생한다. 메모리 침범!
     */

    char source[] = "Copy this!";
    char dest[50];

    strcpy(dest, source);

    cout << source << endl;
    cout << dest << endl;

    // strcat()
    // strcmp()

    strcat(dest, source);
    cout << source << endl;
    cout << dest << endl;

    cout << strcmp(source, dest) << endl;

    // C와 달리 C++에서는 std::string 사용.
}



