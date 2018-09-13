

#ifndef CLION_0911_CPP27_H
#define CLION_0911_CPP27_H

#include <iostream>
#include <limits>


void execFunc() {

    using namespace std;

    char c1(65);
    char c2('A');

    //A A 65 65
    cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
    cout << endl;

    //A
    //C style casting
    cout << (char) 65 << endl;
    cout << (int) 'A' << endl;
    cout << endl;

    //Cpp style casting
    cout << char(65) << endl;
    cout << int('A') << endl;
    cout << endl;

    //위와 달리 캐스팅을 하면서 문제가 없는지 컴파일러에게 확인 요청
    cout << static_cast<char>(65) << endl;
    cout << static_cast<int>('A') << endl;
    cout << endl;

    //static_cast에 변수를 넣을 수도 있다.
    char ch(97);
    cout << ch << endl;
    cout << static_cast<int>(ch) << endl;
    cout << ch << endl;
    cout << endl;

    cout << "입력하세요." << endl;
    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;
    cout << endl;

    //위에서 abc를 입력하면?
    cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;
    cout << endl;

    //limits
    //1     127     -127
    cout << sizeof(char) << endl;
    cout << (int) std::numeric_limits<char>::max() << endl;
    cout << (int) std::numeric_limits<char>::lowest() << endl;
    cout << endl;

    //1     255     0
    cout << sizeof(unsigned char) << endl;
    cout << (int) std::numeric_limits<unsigned char>::max() << endl;
    cout << (int) std::numeric_limits<unsigned char>::lowest() << endl;
    cout << endl;

}

#endif //CLION_0911_CPP27_H
