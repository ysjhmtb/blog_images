#include <iostream>
#include <vector>
#include "DecodeWays.h"
#include "MergeIntervals.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    DecodeWays sol;
    std::cout << sol.numDecodings("226") << std::endl;
    MergeIntervals sol2;
    vector<vector<int>> intervals = {{1,  3},
                                     {2,  6},
                                     {8,  10},
                                     {15, 18}};
    vector<vector<int>> result = sol2.merge(intervals);
    for (vector<int> interval : result) {
        for (int ele : interval) {
            cout << ele << endl;
        }
    }
    return 0;
}
