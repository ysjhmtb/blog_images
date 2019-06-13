```c++
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

/*
    https://leetcode.com/problems/number-of-islands/

     Number of Islands

     1 1 1
     0 1 0
     1 0 0
     1 0 1
 */

class Solution {
public:

    void dfs(int r, int c, vector<vector<char>> &grid) {

        grid.at(r).at(c) = '0';
        if (r > 0 && grid.at(r - 1).at(c) == '1')
            this->dfs(r - 1, c, grid);
        if (r + 1 < grid.size() && grid.at(r + 1).at(c) == '1')
            this->dfs(r + 1, c, grid);
        if (c > 0 && grid.at(r).at(c - 1) == '1')
            this->dfs(r, c - 1, grid);
        if (c + 1 < grid.at(0).size() && grid.at(r).at(c + 1) == '1')
            this->dfs(r, c + 1, grid);
    }

    int numIslands(vector<vector<char>> &grid) {

        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(0).size(); j++) {
                if (grid.at(i).at(j) == '1') {
                    result++;
                    this->dfs(i, j, grid);
                }
            }
        }
        return result;
    }
};

int main() {

    vector<char> a = {'1', '1', '1'};
    vector<char> b = {'0', '1', '0'};
    vector<char> c = {'1', '0', '0'};
    vector<char> d = {'1', '0', '1'};
    vector<vector<char>> grid;
    grid.push_back(a);
    grid.push_back(b);
    grid.push_back(c);
    grid.push_back(d);

    Solution ref;
    int result = ref.numIslands(grid);
    cout << result << endl;

    return 0;
}
```

