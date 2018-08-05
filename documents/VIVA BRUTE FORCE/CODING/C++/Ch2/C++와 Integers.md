

## C++와 Integers





```c++
//
//  main.cpp
//  HelloWorld
//

#include <iostream>
#include <cmath>


int main() {
    using namespace std;
    
    short s = 1;        // 2bytes = 2 * 8 bits = 16bits
    int   i = 1;
    long  l = 1;
    long long ll = 1;
    
    cout << sizeof(short) << endl;          // 2
    cout << sizeof(int) << endl;            // 4
    cout << sizeof(long) << endl;           // 8
    cout << sizeof(long long) << endl;      // 8
    
    // signed short의 경우 32767이 표현할 수 있는 가장 큰 숫자. 부호와 0 때문에 각각 1을 차감.
    cout << std::pow(2, sizeof(short) * 8 - 1 ) - 1  << endl;   //32767
    cout << std::numeric_limits<short>::max()  << endl;         //32767
    cout << std::numeric_limits<short>::min()  << endl;         //-32768
    cout << std::numeric_limits<short>::lowest()  << endl;      //-32768
    
    s = 32767;
    s = s + 1;
    cout << s << endl;  //-32768    overflow
    
    s = std::numeric_limits<short>::min();
    cout << "min() " << s << endl;
    s = s - 1;
    cout << " " << s << endl;   //32767
    
    
    unsigned int ui = -1;
    cout << ui << endl;     //4294967295    C++의 위험성
    
    cout << 22 / 4 << endl; // 5
    cout << (float)22 / 4 << endl; // 5.5
    
    return 0;
}



```

