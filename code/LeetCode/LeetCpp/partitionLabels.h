

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


    Accepted

 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// ababcbaca / defegde / hijhklij
// 012345678
// i=5일 때 종료하지 말고 i=8까지 기다려야 한다. 어떤 조건문을 사용해야 할까? 얼마까지 기다려야 하는지를 저장하고 갱신하자.
class Solution {
public:
    vector<int> partitionLabels(string S) {

        vector<int> result;

        // 각 글자의 마지막 위치를 기록한다.
        map<string, int> maxIndexMap;
        for (unsigned i = 0; i < S.size(); i++) {
            string key = S.substr(i, 1);
            maxIndexMap[key] = i;
//            cout << "key: " << key << " , value: " << i << endl;
        }

        // 시작 지점, 기다려야 할 최대 크기
        int start = 0, maxForWaiting = 0;

        // 기다려야 할 지점까지 도달하면 계산하고 결과에 저장한다.
        for (unsigned i = 0; i < S.size(); i++) {
            string key = S.substr(i, 1);
            maxForWaiting = max(maxForWaiting, maxIndexMap[key]);
            if (i == maxForWaiting) {
                int tempResult = maxForWaiting - start + 1;
                result.push_back(tempResult);
                start = i + 1;
                maxForWaiting = 0;
//                cout << "result: " << tempResult << endl;
            }
        }

        return result;
    }
};

#endif //LEET_PARTITIONLABELS_H

