#include <iostream>

using namespace std;

void doSomethingCpp62(int students_scores[]) {

    cout << &students_scores << endl;
    cout << "size in doSomething : " << sizeof(students_scores) << endl;    // 8 포인터 크기
    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;

}

void cpp62() {

    const int num_students = 20;
    int students_scores[num_students] = {1, 2, 3, 4, 5,};

    /*

     cout << &students_scores << endl; 에서 확인할 수 있는 주소와
     doSomethingCpp62(students_scores); 에서 확인할 수 있는 주소가 다르다.

     cout << sizeof(students_scores) << endl; 와
     doSomethingCpp62(students_scores); 에서 확인할 수 있는 크기가 다르다.




     사이즈 비교를 하려면 CLion의 경우 다음과 같은 과정이 필요했다.


        Setting→Editor→Inspection
        이건 코딩할때 정말 거슬리므로, 그냥 다 끄는게 정신건강에 좋다.
        틀린 부분이 있으면 컴파일러 에러/경고를 보고 고치는게 낫다.
        https://kimbomm.ghost.io/clion-cogi-seoljeong/


     */

    cout << &students_scores << endl;
    cout << "size in main : " << sizeof(students_scores) << endl;   // 4 * 20 = 8
    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << "\n" << endl;

    doSomethingCpp62(students_scores);
    cout << endl;


    /*


     &students_scores와 &(students_scores[0])는 같은 주소.

    cout << &students_scores << endl;
    cout << &(students_scores[0]) << endl;
    cout << &(students_scores[1]) << endl;

     */
    cout << &students_scores << endl;
    cout << &(students_scores[0]) << endl;
    cout << &(students_scores[1]) << endl;


}


