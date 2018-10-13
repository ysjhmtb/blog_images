#include <iostream>

using namespace std;

void cpp6191() {

    int *ptr = nullptr;
    int **ptrptr = nullptr;

    int value = 5;

    ptr = &value;
    ptrptr = &ptr;

    /*
        0x7ffee23059bc      5                   0x7ffee23059c8
        0x7ffee23059c8      0x7ffee23059bc      0x7ffee23059c0
        5
     */

    cout << ptr << " " << *ptr << " " << &ptr << endl;
    cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
    cout << **ptrptr << endl;
}


void cpp6192() {

    const int row = 3;
    const int col = 5;

    const int s2da[row][col] = {
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9,  10},
            {11, 12, 13, 14, 15}
    };


    int **matrix = new int *[row];

    for (int r = 0; r < row; r++) {
        matrix[r] = new int[col];
    }


    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            matrix[r][c] = s2da[r][c];
            cout << matrix[r][c] << " ";

        }
        cout << endl;
    }


    for (int r = 0; r < row; r++) {
        delete[] matrix[r];
    }

    delete[] matrix;

    /*
     *
     *  이중 포인터 사용이 어려울 수 있다. 말로 설명하기가 어렵다.
     *  코드를 보면서 깊이 생각해 볼 것을 추천한다.
     *  그림을 많이 그려볼 것을 추천한다.
     *  홍정모 교수님도 엄청나게 그리면서 이해했다.
     *  수천장 정도 그려본 것 같다.
     *
     *  - 홍정모 교수님
     *
     */

}

void cpp6193() {

    const int row = 3;
    const int col = 5;

    const int s2da[row][col] = {
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9,  10},
            {11, 12, 13, 14, 15}
    };

    int *matrix = new int[row * col];

    /*
     *  c + col * r = 0 + 5 * 1 = 5
     *
     *  matrix[5] = s2da[1][0]
     */
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            matrix[c + col * r] = s2da[r][c];
        }
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << matrix[c + col * r] << " ";
        }
        cout << endl;
    }

}

