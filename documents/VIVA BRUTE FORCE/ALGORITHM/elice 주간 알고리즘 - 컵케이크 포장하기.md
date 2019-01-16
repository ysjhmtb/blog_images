```C++
/*
 https://academy.elice.io/courses/486/lectures/3420/materials/21/


 elice 주간 알고리즘 - 컵케이크 포장하기


엘리스는 이상한 나라의 동물들에게 나누어주기 위해 컵케이크를 만들었습니다.
 컵케이크를 선물하기 위해 봉지에 넣어 포장하던 중 한 가지 사실을 알아차렸습니다.
 봉지에는 두 종류가 있으며, 그중 하나의 봉지에는 컵케이크를 최대 3개 넣을 수 있고,
 다른 봉지에는 최대 5개를 넣을 수 있었습니다.
 엘리스는 각 봉지를 꽉 채워서 포장하면서도 최소 개수의 봉지를 사용하고자 합니다.
 문제를 해결하여 엘리스의 컵케이크 포장을 도와주세요!
 - Made by 김경민님(대덕SW마이스터고)


 문제
 엘리스가 포장하려는 컵케이크의 개수가 총 n개일 때, 필요한 봉지의 최소 개수를 구하는 코드를 작성하세요.
 예를 들어, 18개의 컵케이크를 포장해야 한다면, 3개씩 6봉지로 포장할 수도 있지만, 5개씩 3봉지,
 3개씩 1봉지로 포장하면 더 적은 개수의 봉지를 사용하여 포장할 수 있습니다.


 입력
 첫째 줄에 n이 주어집니다. n은 3보다 크고, 1000보다 작은 자연수입니다.


 출력
 첫째 줄에 필요한 봉지의 최소 개수를 출력합니다. 만약 정확하게 n개의 컵케이크를 포장할 수 없다면 -1을 출력해야 합니다.


 예시 입력 1
 18

 예시 출력 1
 4

 예시 입력 2
 4

 예시 출력 2
 -1


 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

class Solution {
private:
    int cupcakesCount;
    int bag3;
    int bag5;

public:
    Solution(int cupcakesCount)
            : bag3(0), bag5(0) {
        this->cupcakesCount = cupcakesCount;

    }

    bool isThreePossible() {
        if (cupcakesCount != 0 && cupcakesCount >= 3)
            return true;
        else
            return false;
    }

    bool isFivePossible() {
        if (cupcakesCount != 0 && cupcakesCount >= 5)
            return true;
        else
            return false;
    }

    void fillBags() {
        if (isFivePossible()) {
            bag5++;
            cupcakesCount -= 5;

        } else if (isThreePossible()) {
            bag3++;
            cupcakesCount -= 3;
        }
    }

    int last() {
        while (isFivePossible() || isThreePossible()) {
            fillBags();
        }

        if (cupcakesCount == 0)
            return (bag5 + bag3);
        else
            return -1;

    }


};

int main() {


    Solution ref1(18); // 4
    Solution ref2(4); // -1

    std::cout << ref1.last() << std::endl;
    std::cout << ref2.last() << std::endl;

    Solution ref3(71); // -1
    std::cout << ref3.last() << std::endl;

    // 199 * 5 = 995
    Solution ref4(999); // -1
    std::cout << ref4.last() << std::endl;

    return 0;
}

```

