#include <iostream>

using namespace std;


struct Rectange {
    int length;
    int width;
};


enum StudentName {
    JACKJACK,
    DASH,
    VIOLET,
};

void cpp61() {

    int one_student_score;
    int student_scores[5];

    one_student_score = 100;

    student_scores[JACKJACK] = 100;
    student_scores[1] = 80;
    student_scores[2] = 90;
    student_scores[3] = 50;
    student_scores[4] = 0;


    cout << sizeof(Rectange) << endl;

    Rectange rect_arr[10];
    cout << sizeof(rect_arr) << endl;

    rect_arr[0].length = 1;
    rect_arr[0].width = 2;

    int my_arr[5] = {1, 2,};
    cout << my_arr[3] << endl;

    int myArr1[] = {1, 2, 3, 4, 5};
    int myArr2[]{1, 2, 3, 4, 5};    // C++ 11






}