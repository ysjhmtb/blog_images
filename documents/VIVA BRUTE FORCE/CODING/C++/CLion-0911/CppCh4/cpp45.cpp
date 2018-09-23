#include <iostream>
#include <typeinfo>
#include <iomanip>

void cpp45() {

    using namespace std;

    cout << typeid(4.0).name() << endl;

    // implicit conversion
    int a = 123.0;
    cout << typeid(a).name() << endl;

    float b = 1.0f;
    double c = a;       // numeric promotion



    // numeric conversion
    // integer가 char보다 크다.
    int i = 30000;
    char ch = i;

    // 48
    cout << static_cast<int>(ch) << endl;

    double d = 0.123456789;
    float f = d;
    // 0.123456791043
    cout << std::setprecision(12) << f << endl;


    i = 1234;
    f = i;
    // 1234
    cout << std::setprecision(12) << f << endl;


    f = 3.14;
    i = f;
    // 3
    cout << std::setprecision(12) << i << endl;


    // unsigned 5 - 10 = ?
    // 4294967291
    // 형 변환 우선순위 :
    // int 가 가장 낮다 < unsigned int < long < unsigned long
    // < long long < unsigned long long < float < double
    // < long double
    cout << 5u - 10 << endl;


    // explicit conversion
    int i1 = int(4.0);      // C++ style
    int i2 = (int)4.0;      // C style
    int i3 = static_cast<int>(4.0);






}