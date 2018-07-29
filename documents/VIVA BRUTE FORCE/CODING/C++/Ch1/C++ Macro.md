## C++ Macro

요즘에는 매크로는 많이 사용하지 않고, 함수를 사용한다.   



```C++
//
 //  defineTest.cpp
 //  HelloWorld
 //
 
 #include <iostream>
 
 
 void doSomething(){
 
 using namespace std;
 
 #ifdef LIKE_APPLE
 cout << "APPLE" << endl;
 #endif
 
 #ifndef LIKE_APPLE
 cout << "Orange" << endl;
 #endif
 
 }
 
```







```C++
//
 //  main.cpp
 //  HelloWorld
 //
 
 #include <iostream>
 #include <algorithm>
 using namespace std;
 
 
 #define MAX(a,b) ( ( (a) > (b) ) ? (a) : (b) )
 
 
 
 #define LIKE_APPLE
 void doSomething(); 
 
 
 int main() {
 
     cout << MAX(3,4) << endl;
     cout << std::max(1+3, 2) << endl;

     //APPLE이 출력될 것 같지만 Orange가 나온다.
     //왜냐하면 #define LIKE_APPLE 는 현재 파일 내에서만 유효하다.

     doSomething();

     return 0;
 }
```





