```C++
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

/*
 https://leetcode.com/problems/maximum-subarray/

 Maximum Subarray

 Input: [-2,1,-3,4,-1,2,1,-5,4],
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 */

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int curSum = nums.at(0);
        int maxSum = nums.at(0);

        for (unsigned i = 1; i < nums.size(); i++) {
            curSum = max(curSum + nums.at(i), nums.at(i));
            maxSum = max(curSum, maxSum);
        }

        return maxSum;
    }
};

int main() {

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution ref;
    cout << ref.maxSubArray(nums) << endl;

    return 0;
}
```

