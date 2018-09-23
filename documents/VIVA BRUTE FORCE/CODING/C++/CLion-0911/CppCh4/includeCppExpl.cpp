/*
 *
 *
 * cpp 파일에서 다른 cpp 파일을 호출할 수 있는 방법은 한 가지가 아니다.
 *
 *
 *
 * 1)
 *
 * 우선
 *
 *
 *
         You need to define your functions in *.cpp files, and then declare them
         in corresponding headers like:

         function.cpp

            void myFunction()
            {
                //Blah, blah, blah...
            }


         function.h

            void myFunction();


         and main.cpp

            #include "function.h"
            myFunction();



         http://www.cplusplus.com/forum/beginner/97779/

 *
 *
 *
 * 와 같은 방법이 있다.
 *
 *
 * CppCh2/test.cpp 에
 *
 * void test(){
 *  cout << "this is test \n\n" << endl;
 * }
 *
 * 를 만들고,
 *
 * CppCh2/test.h 에
 *
 * void test();
 *
 * 를 기술한 후 main()에서
 *
 * #include "CppCh2/test.h" 를 적고
 *
 * test() 함수를 사용.
 *
 *
 *
 *
 *
 * 2)
 *
 * CppCh4/cpp42external.cpp 에
 *
 *
 *
 * void doSomethingExternal() {
 *      using namespace std;
 *      cout << "Hello" << endl;
 * }
 *
 * 를 만들고,
 *
 * main()에서
 *
 * // forward declaration
 * extern void doSomethingExternal();
 *
 * 를 선언 후
 *
 * doSomethingExternal(); 를 사용.
 *
 *
 *
 *
 *
 *
 *
 * 함수뿐만 아니라 변수에도 똑같이 사용될 수 있다.
 *
 *
 * CppCh4/cpp42external.cpp 에 int aExternal = 1;
 * 를 선언한 후
 *
 * main()에서  extern int a;를 기술하면 변수를 사용할 수 있다.
 *
 *
 *
 *
 */



