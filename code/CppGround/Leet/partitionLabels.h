

#ifndef LEET_PARTITIONLABELS_H
#define LEET_PARTITIONLABELS_H

/*
 * https://leetcode.com/problems/partition-labels/
 *
 *
 * Input: S = "ababcbacadefegdehijhklij"
    Output: [9,7,8]
    Explanation:
    The partition is "ababcbaca", "defegde", "hijhklij".
    This is a partition so that each letter appears in at most one part.
    A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.


    1) a, b, c 등 각각의 글자가 마지막으로 등장하는 인덱스를 기록한다.
    2) 카운트 변수와 시작 지점 변수를 초기화 한다.
    3) 현재 지점에서 카운트 변수에 최대의 값을 넣어준다.
    4) 카운트 변수에 들어있는 값이 한개의 순회에서 도달해야 할 지점이다.
    5) 한 글자씩 검사하면서 카운트 변수를 갱신해 주고, 원하는 지점에 도달하면 결과를 계산한다.


 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {

    }
};

#endif //LEET_PARTITIONLABELS_H

