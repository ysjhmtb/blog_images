


#include <iostream>
#include "MyConstants.h"

int aExternal = 1;

void doSomethingExternal() {
    using namespace std;

    cout << "in doSomethingExternal : " << Constants::pi << "  " << &Constants::pi << endl;
}


/*
 *
 * 1)
 *
 * MyConstants.h 에
 *
 *      namespace Constants{
 *          const double pi(3.141592);
 *          const double gravity(9.8);
 *       }
 *
 * 이 있고,
 *
 * main()에서
 *
 * cout << "in main() : " << Constants::pi << "  " << &Constants::pi << endl;
 * doSomethingExternal();
 *
 * 를 실행시켜 보면
 *
 * Constants::pi의 메모리 주소가 다름을 확인할 수 있다. 메모리의 낭비.
 *
 *
 *
 *
 *
 *
 *
 * 2)
 *
 * 이번에는
 *
 * MyConstants.h 에서
 *
 *      namespace Constants{
 *          extern const double pi;
 *          extern const double gravity;
 *      }
 *
 * 선언만 하고,
 *
 *
 * MyConstants.cpp 에서
 *
 *      namespace Constants {
 *          extern const double pi(3.141592);
 *          extern const double gravity(9.8);
 *      }
 *
 * 를 기술하고,
 *
 *
 * main()에서
 *
 *
 * cout << "in main() : " << Constants::pi << "  " << &Constants::pi << endl;
 * doSomethingExternal();
 *
 *
 * 를 실행시켜 보면
 *
 *
 * 이번에는 메모리 주소가 같음을 알 수 있다.
 *
 *
 *
 *
 *
 */





/*
 *      int g_x;            // global. external linkage로 쓸 수도 있다. 초기화가 안된 전역변수.
 *      static int g_z;     // global. internal linkage. 다른 cpp 파일에서 이 변수에 접근 불가.
 *      const int g_x;      // global. 불가. 초기화를 안해주고 있다. 초기화를 해야 한다.
 *
 *      extern int g_z;         // global. forward declaration.
 *      extern const int g_z    // global. 가능. 단, 다른 곳에서 초기화를 해주어야 한다.
 *
 *      int g_y(1);             // 초기화.
 *      static int g_y(1);      // 다른 cpp 파일에서 접근 불가. 초기화.
 *      const int g_y(1);       // 일반적인 상수 선언. 같은 파일 안에서 접근.
 *
 *      extern int g_w(1);
 *      extern const int g_w(1);    // 상수고, 초기화도 됐고, 다른 cpp 파일에서도 접근.
 *
 *
 *
 *
 */