#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

void cpp6211() {

    // std::array<int, 5> array;
    std::vector<int> array;

    std::vector<int> array2 = {1, 2, 3, 4, 5};
    cout << array2.size() << endl;

    std::vector<int> array3 = {1, 2, 3,};
    cout << array3.size() << endl;

    std::vector<int> array4 = {1, 2, 3, 4,};
    cout << array4.size() << endl;

}

void cpp6212() {

    int *my_arr = new int[5];

    std::vector<int> arr{1, 2, 3, 4, 5};

    arr.resize(10);

    for (auto &itr:arr) {
        cout << itr << " ";
    }
    cout << endl;

    // vector의 장점 중 하나는 delete 연산이 불필요하다.
    delete[] my_arr;

}
