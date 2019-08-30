

#ifndef LEET_MEDIANOFTWOSORTEDARRAYS_H
#define LEET_MEDIANOFTWOSORTEDARRAYS_H

/*
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 *
 * []
 * [1]
 * 1.0
 *
 * [3]
 * [-2,-1]
 * -1.0
 *
 * 1. 각 벡터를 하나씩 검사한다. 벡터의 길이가 짝수인지 홀수인지 판단한다.
 * 2. 짝수라면 벡터의 길이를 2로 나누고, 몫이 필요한 인덱스의 두번째다. 따라서 몫-1과 몫이 필요한 인덱스다.
 *    이 인덱스에 해당하는 값을 2로 나눈 실수가 절반의 중위값이다.
 * 3. 홀수라면 벡터의 길이를 2로 나누고, 몫이 필요한 인덱스의 전부이다. 따라서 인덱스의 값이 절반의 중위값 자체이다.
 * 4. 절반의 중위값을 더한 후 2로 나눈 실수값이 결과다.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    double getMedian(vector<int> nums) {

        if (nums.size() == 0)
            return 0;

        if (nums.size() % 2 == 0) {
            int secondIndex = nums.size() / 2;
            int firstIndex = secondIndex - 1;
            double median = (double) (nums.at(firstIndex) + nums.at(secondIndex)) / 2.0;
            return median;
        } else {
            int index = nums.size() / 2;
            return (double) nums.at(index);
        }
    }

public:

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        double firstMedian = this->getMedian(nums1);
        double secondMedian = this->getMedian(nums2);

        double result = 0.0;

        if (nums1.size() == 0) {
            result = (double) secondMedian;
        } else if (nums2.size() == 0) {
            result = (double) firstMedian;
        } else {
            result = (double) (firstMedian + secondMedian) / 2.0;
        }

        return result;
    }
};

#endif //LEET_MEDIANOFTWOSORTEDARRAYS_H
