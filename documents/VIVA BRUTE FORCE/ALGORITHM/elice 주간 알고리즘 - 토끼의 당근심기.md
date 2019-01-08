

```C++
/*

 https://academy.elice.io/courses/486/lectures/3420/materials/24

 elice 주간 알고리즘 - 토끼의 당근심기

 토끼가 당근을 심으려고 하는데, 밭에 잡초가 있어서 토끼가 어려움을 겪고 있어요. 토끼를 도와 당근농사를 성공적으로 마무리해봅시다.

 ----- ----- ----- -----

 토끼가 농사를 짓는 밭은 1X1 크기의 작은 땅으로 이루어져있습니다. 이 땅에는 잡초가 심어져있거나, 심어져있지 않는데,
 토끼는 반드시 잡초가 심어져있지 않는 땅에만 농사를 지을수 있고, 농사는 반드시 '정사각형 모양의 밭’에만 지을 수 있습니다.
 예를들어, 다음과 같이 밭 상황이 주어져있을 때, 토끼는 이 녹색 부분에 농사를 지을 수 있습니다.

 ----- ----- ----- -----

 이 상황에서 잡초가 있는 땅을 0, 잡초가 없는 땅을 1이라고 할 때, 토끼가 농사를 지을 수 있는 가장 큰 땅의 넓이를 출력해봅시다.
 예를 들어, 왼쪽 그림과 같은 밭이 주어졌을 때, 잡초가 없는 땅으로 만들 수 있는 가장 큰 정사각형 모양의 잡초밭은 오른쪽의 녹색과 같고,
 이것의 넓이인 2X2 = 4를 반환합니다.


 입력
 첫째 줄에 nn, mm(1 ≤ n,mn,m ≤ 1000)이 주어집니다.
 다음 nn개의 줄에는 mm개의 숫자가 차례로 주어집니다.

 출력
 첫째 줄에 가장 큰 잡초밭의 넓이을 출력합니다.

 예시 입력

 5 5
 0 1 1 0 1
 0 1 1 0 1
 0 0 0 0 0
 0 1 1 0 1
 0 0 1 1 1

 예시 출력
 4

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class Solution {
private:
    unsigned int row;
    unsigned int col;
    std::vector<std::vector<int> > m_field;
    unsigned int maxSize;

public:
    Solution(const unsigned int &row, const unsigned int &col, const std::vector<std::vector<int> > field) {
        this->row = row;
        this->col = col;
        this->maxSize = 0;

        for (unsigned int i = 0; i < row; i++) {

            std::vector<int> temp;

            for (unsigned int j = 0; j < col; j++) {
                temp.push_back(field[i][j]);
            }

            m_field.push_back(temp);
        }
    }

    bool hasAllOne(unsigned int i, unsigned int j, unsigned int len) {
        bool flag = true;

        if (i + len >= row || j + len >= col)
            return false;

        for (unsigned int k = i; k <= i + len; k++) {
            for (unsigned int l = j; l <= j + len; l++) {
                if (m_field[k][l] != 1) {
                    flag = false;
                    return flag;
                }
            }
        }

        return flag;
    }

    void investigateAll() {

        unsigned tempSize = 0;
        unsigned tempLen = 0;

        for (unsigned i = 0; i < row; i++) {

            for (unsigned j = 0; j < col; j++) {


                while (this->hasAllOne(i, j, tempLen)) {

                    unsigned tempInside = 0;

                    if (tempLen < 1) {
                        tempInside = 1;
                    } else {
                        tempInside = pow(tempLen + 1, 2);
                    }

                    maxSize = std::max(maxSize, tempInside);
                    tempLen++;


                }
                tempLen = 0;
            }

        }

    }

    int getMaxSize() { return maxSize; }

};

int main() {

    int row = 5;
    int col = 5;
    std::vector<std::vector<int> > field;

    std::vector<int> temp1{0, 1, 1, 0, 1};
    std::vector<int> temp2{0, 1, 1, 0, 1};
    std::vector<int> temp3{0, 0, 0, 0, 0};
    std::vector<int> temp4{0, 1, 1, 0, 1};
    std::vector<int> temp5{0, 0, 1, 1, 1};

    field.push_back(temp1);
    field.push_back(temp2);
    field.push_back(temp3);
    field.push_back(temp4);
    field.push_back(temp5);

    Solution ref(row, col, field);

    std::cout << std::boolalpha;

    ref.investigateAll();
    std::cout << ref.getMaxSize() << std::endl;

    return 0;
}

```

