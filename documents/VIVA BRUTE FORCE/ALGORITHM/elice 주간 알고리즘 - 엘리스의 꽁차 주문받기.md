

```C++
/*
    https://academy.elice.io/courses/486/lectures/3420/materials/22

    elice 주간 알고리즘 - 엘리스의 꽁차 주문받기

    엘리스는 세계에서 가장 맛있는 밀크티를 만드는 꽁차에서 카운터를 담당하고 있습니다.
    엘리스는 너무 많은 손님이 오는 바람에 다음과 같은 방법으로 주문을 접수합니다.
    주문이 들어오면 주문 대기줄의 맨 마지막에 추가합니다.
    주문 대기줄의 맨 앞에 있는 주문의 "시킨 음료의 개수"를 확인합니다.
    만약 주문 대기줄에 있는 다른 주문 중 현재 확인한 주문보다 시킨 음료의 개수가 많은 주문이 있다면,
    현재 주문을 접수하지 않고 주문 대기줄의 가장 뒤로 보냅니다. 그렇지 않다면 현재 주문을 접수합니다.
    예를들어, 3명의 손님 정우, 유현, 경진이 순서대로 와서 각각 3잔, 2잔, 5잔을 시켰다면,
    엘리스는 경진이의 주문을 먼저 받고, 그 뒤로 정우, 유현 순으로 주문을 접수합니다.
    어느날 토끼가 밀크티가 먹고싶어 꽁차에 와서 주문을 했습니다.
    엘리스는 주문 대기줄에서 토끼가 몇번째로 주문했는지 알고 있을 때,
    엘리스를 도와서 토끼의 주문이 몇 번째로 접수되는지 확인해봅시다!



    입력
    맨 첫 줄에 테스트 케이스의 개수 T가가 주어집니다. 그 다음 줄 부터는 아래의 1,2 번이 T번 반복됩니다.
    전체 주문의 수 n (1 ≤ n ≤ 100)과 토끼가 주문한 순서를 나타내는 인덱스 m (0 ≤ m ＜ n)이 주어집니다.
    n명의 손님이 주문한 음료 개수가 각각 주어집니다. (※ 손님이 주문한 음료의 개수는 같을 수 있습니다.)



    출력
    각 테스트케이스에 대해 토끼의 주문이 몇 번째로 접수되는지 출력합니다.



    예제 입력
    2 # T
    3 2 # n m
    3 2 5 # 손님 3명이 주문한 각 음료 개수
    4 1 # n m
    1 2 3 4 # 손님 4명이 주문한 각 음료 개수



    예제 출력
    1
    3


*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

class Solution {
private:
    int orderAmount;
    int rabbitIndex;
    std::vector<int> beverages;

public:

    Solution(int orderAmount, int rabbitIndex, std::vector<int> beverages) {

        this->orderAmount = orderAmount;
        this->rabbitIndex = rabbitIndex;

        for (unsigned i = 0; i < beverages.size(); i++) {
            this->beverages.push_back(beverages.at(i));
        }

        std::cout << this->orderAmount << std::endl;
        std::cout << this->rabbitIndex << std::endl;

        for (unsigned i = 0; i < beverages.size(); i++) {
            std::cout << this->beverages.at(i) << "  ";
        }

        std::cout << std::endl << std::endl;


    }

    bool havetoChange() {
        bool temp = false;

        for (unsigned i = 1; i < beverages.size(); i++) {
            if (beverages.at(0) < beverages.at(i)) {
                temp = true;
                return temp;
            }
        }

        return temp;
    }

    void changeBeverages() {
        int firstBeverage = beverages.at(0);

        if (rabbitIndex == 0) {
            rabbitIndex = orderAmount - 1;
        } else {
            rabbitIndex--;
        }

        beverages.erase(beverages.begin());
        beverages.push_back(firstBeverage);
    }

    int last() {
        while (havetoChange()) {
            changeBeverages();
        }
        int result = ++rabbitIndex;
        return result;

    }


};

int main() {

    int oa1(3);
    int ri1(2);
    std::vector<int> b1{3, 2, 5};

    int oa2(4);
    int ri2(1);
    std::vector<int> b2{1, 2, 3, 4};

    Solution ref1(oa1, ri1, b1);
    Solution ref2(oa2, ri2, b2);

    std::cout << ref1.last() << std::endl;
    std::cout << ref2.last() << std::endl;


    return 0;
}

```

