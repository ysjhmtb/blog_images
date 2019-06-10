```C++
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
 https://leetcode.com/problems/rotate-image/

 Rotate Image

 Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]


Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 */

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {

        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix.at(i).at(j);
                matrix.at(i).at(j) = matrix.at(j).at(i);
                matrix.at(j).at(i) = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (n / 2); j++) {
                int temp = matrix.at(i).at(j);
                matrix.at(i).at(j) = matrix.at(i).at(n - 1 - j);
                matrix.at(i).at(n - 1 - j) = temp;
            }
        }

    }
};

int main() {

    vector<int> a1 = {1, 2, 3};
    vector<int> a2 = {4, 5, 6};
    vector<int> a3 = {7, 8, 9};
    vector<vector<int>> a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);

    vector<int> b1 = {5, 1, 9, 11};
    vector<int> b2 = {2, 4, 8, 10};
    vector<int> b3 = {13, 3, 6, 7};
    vector<int> b4 = {15, 14, 12, 16};
    vector<vector<int>> b;
    b.push_back(b1);
    b.push_back(b2);
    b.push_back(b3);
    b.push_back(b4);

    Solution ref;
    ref.rotate(a);
    ref.rotate(b);

    return 0;
}
```

