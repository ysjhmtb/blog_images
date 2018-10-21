
/*
 *  C++ 더 쉽게, 더 깊게  116페이지
 *
 *  동전 던지기를 흉내 내는 프로그램을 작성하라. 이 프로그램을 여러 번 실행한 뒤
 *  결과가 한쪽으로 치우치치 않는지 확인하라.
 */



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


/*
 *  0~9     범위를 원하면 / 10
 *  0~10    범위를 원하면 / 11
 */

int randRange(int low, int high) {

    return rand() % (high - low + 1) + low;
}


int main() {

    srand(time(NULL));

    int frontCount = 0;
    int rearCount = 0;
    int errorCount = 0;


    for (int i = 0; i < 1000; i++) {

        int temp = randRange(0, 1);

        if (temp == 0) {
            frontCount++;
        } else if (temp == 1) {
            rearCount++;
        } else {
            errorCount++;
        }

        cout << temp << endl;
    }

    cout << "결과 확인 " << endl;
    cout << "앞면 : " << frontCount << endl;
    cout << "뒷면 : " << rearCount << endl;
    cout << "에러 : " << errorCount << endl;

    return 0;
}