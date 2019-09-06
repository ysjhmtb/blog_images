
#ifndef LEET_TRAPPINGRAINWATER_H
#define LEET_TRAPPINGRAINWATER_H

/*
 * https://leetcode.com/problems/trapping-rain-water/
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 * 1. 첫 인덱스와 마지막 인덱스는 검사하지 않아도 된다.
 * 2. 현재 인덱스에서 좌측 최대 높이와 우측 최대 높이를 판단한다.
 * 3. 낮은 쪽 장벽이 가능한 저량이다.
 * 4. 만일 어느 한쪽의 최대 높이가 현재 인덱스의 높이보다 낮다면 저량은 0이다.
 *
 * Accepted
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {

private:

    vector<int> getLeftRightWallMaxHeight(vector<int> &height, int curidx) {


        assert(0 < curidx && curidx < height.size() - 1);
        vector<int> leftRight;

        int leftidx = curidx - 1;
        int rightidx = curidx + 1;
        int leftMax = height.at(leftidx);
        int rightMax = height.at(rightidx);

        while (leftidx > 0) {
            leftMax = max(leftMax, height.at(leftidx - 1));
            leftidx -= 1;
        }
        while (rightidx < height.size() - 1) {
            rightMax = max(rightMax, height.at(rightidx + 1));
            rightidx += 1;
        }

        leftRight.push_back(leftMax);
        leftRight.push_back(rightMax);

        return leftRight;
    }

public:

    int trap(vector<int> &height) {
        int result = 0;
        for (unsigned i = 0; i < height.size(); i++) {
            if (0 < i && i < height.size() - 1) {

                vector<int> leftRight = this->getLeftRightWallMaxHeight(height, i);
                if (leftRight.at(0) <= height.at(i) || height.at(i) >= leftRight.at(1))
                    continue;

                result += (leftRight.at(0) < leftRight.at(1) ? leftRight.at(0) - height.at(i) : leftRight.at(1) -
                                                                                                height.at(i));
            }
        }
        return result;
    }
};


#endif //LEET_TRAPPINGRAINWATER_H
