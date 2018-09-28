#include <iostream>

using namespace std;

void cpp55() {


    cout << "while-loop test" << endl;

    while (1) {
        static int count = 0;
        cout << count << endl;
        ++count;

        if (count == 10) break;
    }

}

void cpp55a() {

    cout << "while-loop test" << endl;

    /*
     * 다음처럼 overflow 위험에도 불구하고
     * int가 아닌 unsigned int를 사용하는 이유?
     *
     * 최적화를 하기 시작하면 작은 부분에서의 절약도 중요함.
     * 파이썬, 자바, 자바스크립트 같은 언어가 편함에도 불구하고
     * C++가 사용되는 이유.
     *
     * 홍정모 교수님 말씀에 따르면
     * unsigned int 계산이 signed int 보다 조금 더
     * 빠를 수 있다고 들으셨다고 함.
     *
     */
    unsigned int count = 10;

    while (count >= 0) {
        if (count == 0) cout << "zero";
        else cout << count << " ";
        count--;
    }
}


void cpp55b() {
    /*

        *
       ***
      *****
     *******


     */

    for (int i = 0; i < 4; i++) {

        int j = 3;
        static int startCount = 1;
        int k = startCount;

        int jCount = j - i;
        while (jCount > 0) {
            cout << " ";
            jCount--;
        }

        while (k > 0) {
            cout << "*";
            k--;
        }

        startCount += 2;
        cout << endl;


    }

}