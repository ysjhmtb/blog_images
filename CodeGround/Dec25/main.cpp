
// main.cpp

/*
    https://academy.elice.io/courses/486/lectures/3420/materials/23

    elice 주간 알고리즘 - 모자 사기 좋은 날

    어느 날 엘리스가 길을 가다가 아주 멋있는 모자를 팔고있는 가게를 발견했습니다.
    이곳에는 특이한 점이 있었는데, 모자마다 제각각 고유번호가 붙어있었습니다.

    엘리스가 다음과 같이 말했더니,

    “혹시 이 모자를 구매하려면 어떻게 해야하나요?”
    모자장수는 다음과 같이 답했습니다.

    “당신이 고유번호가 N인 모자를 사기 위해선 N번째 거울 수만큼의 돈을 지불해야합니다”
    엘리스를 도와 얼마를 지불해야하는지 알아내봅시다.



    문제
    11, 404, 120021과 같이 올바르게 읽거나 거꾸로 읽어도 같은 수를 '거울 수’라고 합니다.
    예를 들어, 202라는 수는 0, 1, … , 191, 202로 30번째 거울 수입니다.
    어떤 모자의 고유 번호 N을 입력했을 때 N번째 거울 수를 출력하는 코드를 작성해봅시다.


    입력
    첫번째 줄에 모자의 고유 번호 N(1≤N≤10,000,000)이 주어집니다.

    출력
    N번째 거울 수를 출력합니다.


    예시 입력 1
    30

    예시 출력 1
    202


    예시 입력 2
    121

    예시 출력 2
    2112



    11 22 33 44 55 66 77 88 99
    101 111 121 131 141 151 161 171 181 191
    1001 1111 1221 1331 1441 1551 1661 1771 1881 1991
    10001 11011 11111

    후보들을 먼저 모두 나열한 후에 다시 방법을 찾기.


 */

#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    std::vector<int> candidates;

public:
    bool isMirror(int number) {
        std::string temp = std::to_string(number);  // 101 1001

        int i = 0;
        int j = temp.length() - 1;
        while (i <= j) {
            if (temp.at(i) != temp.at(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {

    Solution ref;

    std::cout << std::boolalpha;
    std::cout << ref.isMirror(101) << std::endl;
    std::cout << ref.isMirror(1001) << std::endl;
    std::cout << ref.isMirror(1010) << std::endl;


    return 0;
}


