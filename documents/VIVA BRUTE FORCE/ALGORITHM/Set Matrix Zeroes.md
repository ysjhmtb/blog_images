```C++
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

/*
 https://leetcode.com/problems/set-matrix-zeroes/

 Set Matrix Zeroes

 Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

 */



class Solution {

public:
    void setZeroes(vector<vector<int>> &matrix) {

        for (unsigned i = 0; i < matrix.size(); i++) {
            for (unsigned j = 0; j < matrix.at(0).size(); j++) {
                if (matrix.at(i).at(j) == 0) {
                    for (unsigned k = 0; k < matrix.at(0).size(); k++) {
                        if (matrix.at(i).at(k) != -1000 && matrix.at(i).at(k) != 0) {
                            matrix.at(i).at(k) = -1000;
                        }
                    }

                    for (unsigned k = 0; k < matrix.size(); k++) {
                        if (matrix.at(k).at(j) != -1000 && matrix.at(k).at(j) != 0) {
                            matrix.at(k).at(j) = -1000;
                        }
                    }
                }
            }
        }

        for (unsigned i = 0; i < matrix.size(); i++) {
            for (unsigned j = 0; j < matrix.at(0).size(); j++) {
                if (matrix.at(i).at(j) == -1000) {
                    matrix.at(i).at(j) = 0;
                }
            }
        }
    }
};


int main() {

    vector<vector<int> > matrix;
    vector<int> a = {0, 1, 2, 0};
    vector<int> b = {3, 4, 5, 2};
    vector<int> c = {1, 3, 1, 5};
    matrix.push_back(a);
    matrix.push_back(b);
    matrix.push_back(c);

    Solution ref;
    ref.setZeroes(matrix);

    return 0;
}
```

