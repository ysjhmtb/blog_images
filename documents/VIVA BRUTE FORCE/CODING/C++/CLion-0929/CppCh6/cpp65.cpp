#include <iostream>

using namespace std;

void cpp65() {

    const int num_rows = 3;
    const int num_columns = 5;

    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < num_columns; ++col) {
            cout << '[' << row << ']' << '[' << col << ']' << '\t';
        }
        cout << endl;
    }

    cout << endl;




    // row-major 방식. column-major 방식도 있다.
    // int array[num_rows][num_columns] = {0}; 도 가능.
    int array[num_rows][num_columns] =
            {
                    {1,  2,  3,  4,  5},
                    {6,  7,  8,  9,  10},
                    {11, 12, 13, 14, 15}
            };



    /*

     cout << &array[row][col] << '\t';  -

     0x7ffee0a199b0	0x7ffee0a199b4	0x7ffee0a199b8	0x7ffee0a199bc	0x7ffee0a199c0
     0x7ffee0a199c4	0x7ffee0a199c8	0x7ffee0a199cc	0x7ffee0a199d0	0x7ffee0a199d4
     0x7ffee0a199d8	0x7ffee0a199dc	0x7ffee0a199e0	0x7ffee0a199e4	0x7ffee0a199e8



     cout << array[row][col] << '\t';   -

     1	2	3	4	5
     6	7	8	9	10
     11	12	13	14	15

     */

    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < num_columns; ++col) {
            cout << &array[row][col] << '\t';
        }
        cout << endl;
    }

    cout << endl;





}