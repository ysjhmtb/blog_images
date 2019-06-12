```c++
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

/*
 https://leetcode.com/problems/binary-tree-level-order-traversal/

 Binary Tree Level Order Traversal

 For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode *node, int level, vector<vector<int> > &levels) {
        if (levels.size() == level) {
            vector<int> temp;
            levels.push_back(temp);
        }

        levels.at(level).push_back(node->val);

        if (node->left != NULL)
            this->helper(node->left, level + 1, levels);

        if (node->right != NULL)
            this->helper(node->right, level + 1, levels);
    }

    vector<vector<int>> levelOrder(TreeNode *root) {

        if (root == NULL) {
            vector<vector<int> > temp;
            return temp;
        }

        vector<vector<int> > levels = {};
        this->helper(root, 0, levels);
        return levels;
    }
};


int main() {

    struct TreeNode a(3);
    struct TreeNode b(9);
    struct TreeNode c(20);
    struct TreeNode d(15);
    struct TreeNode e(7);

    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;

    Solution ref;
    ref.levelOrder(&a);

    return 0;
}
```

