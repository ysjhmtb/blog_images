## C++ 고정 너비 정수 Fixed width Integers



```C++
//
//  main.cpp
//  HelloWorld
//

#include <iostream>


int main() {
    using namespace std;
   
    std::int16_t i(5);
    std:int8_t myint = 65;  //char로 컴파일 된다.
    
    cout << myint << endl;  //A가 출력되는 것을 확인할 수 있다.
    
    std::int_fast8_t fi(5);     //int 8비트 중에서 가장 빠른 데이터 타입
    std::int_least64_t fl(5);   //int 적어도 8바이트를 갖는 데이터 타입
    
    
    return 0;
}



```

