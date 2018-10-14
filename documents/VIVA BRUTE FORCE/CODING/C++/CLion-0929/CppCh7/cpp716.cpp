#include <iostream>
#include <cstdarg>  // for ellipsis

using namespace std;

double findAverage716(int count, ...) {

    double sum = 0;

    va_list list;

    va_start(list, count);

    for (int arg = 0; arg < count; arg++) {
        sum += va_arg(list, int);
    }

    va_end(list);

    return sum / count;
}


void cpp716() {

    // 생략부호 Ellipsis

    /*
        1
        2
        3
        -3.49241e+08
     */
    cout << findAverage716(1, 1, 2, 3, "Hello", 'c') << endl;
    cout << findAverage716(3, 1, 2, 3) << endl;
    cout << findAverage716(5, 1, 2, 3, 4, 5) << endl;
    cout << findAverage716(10, 1, 2, 3, 4, 5) << endl;  // 갯수와 실제 인수가 차이가 나면 안된다.


}