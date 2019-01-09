



```C++
/*

    https://academy.elice.io/courses/486/lectures/3420/materials/23

    elice 주간 알고리즘 - 연속부분최대합

    n개의 숫자가 주어질 때, 연속 부분을 선택하여 그 합을 최대화 하는 프로그램을 작성해봅니다.

    다음과 같이 8개의 숫자가 있다고 하자.

    1 2 -4 5 3 -2 9 -10

    이 때, 연속 부분이란 연속하여 숫자를 선택하는 것을 말한다.
    가능한 연속 부분에는 [1, 2, -4], [5, 3, -2, 9], [9, -10] 등이 있을 수 있다. 이 연속 부분들 중에서
    가장 합이 큰 연속 부분은 [5, 3, -2, 9] 이며, 이보다 더 합을 크게 할 수는 없다.
    따라서 연속 부분 최대합은 5+3+(-2)+9 = 15 이다.


    입력
    첫째 줄에 nn개의 숫자가 주어진다. (1 \leq n \leq 1001≤n≤100)

    출력
    n개의 숫자에 대하여 연속 부분 최대합을 출력한다.

    입력 예시
    1 2 -4 5 3 -2 9 -10

    출력 예시
    15

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

class Solution {
private:
    std::vector<int> candidates;
    int maxSum;

public:
    Solution(const std::vector<int> &candidates) {
        for (unsigned i = 0; i < candidates.size(); i++) {
            this->candidates.push_back(candidates.at(i));

        }
    }

    // end open interval
    int getSumRange(const unsigned &start, const unsigned &end) {

        assert(start >= 0 && end <= (this->candidates.size()));

        int tempSum(0);

        for (unsigned i = start; i < end; i++) {
            tempSum += this->candidates.at(i);
        }

        return tempSum;

    }


    int getAnswer() {

        for (unsigned i = 0; i < (this->candidates.size() - 1); i++) {
            unsigned end = i + 1;
            while (end <= this->candidates.size()) {
                int temp = this->getSumRange(i, end);
                this->maxSum = std::max(this->maxSum, temp);
                end++;
            }
        }

        return this->maxSum;

    }

};

int main() {

    std::vector<int> candidates{1, 2, -4, 5, 3, -2, 9, -10};
    Solution ref(candidates);

    std::cout << ref.getAnswer() << std::endl;
    return 0;
}


```

