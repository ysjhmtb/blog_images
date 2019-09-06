

#ifndef LEET_ALLNODESDISTANCEKINBINARYTREE_H
#define LEET_ALLNODESDISTANCEKINBINARYTREE_H

/*
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

    Output: [7,4,1]

    Explanation:
    The nodes that are a distance 2 from the target node (with value 5)
    have values 7, 4, and 1.

 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {

    }
};

#endif //LEET_ALLNODESDISTANCEKINBINARYTREE_H
