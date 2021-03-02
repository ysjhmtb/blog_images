
#ifndef LEETCODECPP_MERGEINTERVALS_H
#define LEETCODECPP_MERGEINTERVALS_H

/*
https://leetcode.com/problems/merge-intervals/

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */

using namespace std;
#include <vector>
/*
#include <vector>이 없으면 아래의 문제가 나타남.
Implicit instantiation of undefined template 'std::__1::vector<std::__1::vector<int,
 std::__1::allocator<int>>, std::__1::allocator<std::__1::vector<int, std::__1::allocator<int>>>>'
 */

class MergeIntervals {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
                // otherwise, there is overlap, so we merge the current and previous
                // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

#endif //LEETCODECPP_MERGEINTERVALS_H
