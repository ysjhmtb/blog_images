> 654. [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/description/)
>
> Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
>
> 1. The root is the maximum number in the array.
> 2. The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
> 3. The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
>
> Construct the maximum tree by the given array and output the root node of this tree.
>
> **Example 1:**
>
> ```
> Input: [3,2,1,6,0,5]
> Output: return the tree root node representing the following tree:
> 
>       6
>     /   \
>    3     5
>     \    / 
>      2  0   
>        \
>         1
> ```
>
> **Note:**
>
> 1. The size of the given array will be in the range [1,1000].

<br>

[[Java/C++] Simple recursive method.](https://leetcode.com/problems/maximum-binary-tree/discuss/106194/JavaC++-Simple-recursive-method.) 의 다음 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        int[] num = new int[]{3, 2, 1, 6, 0, 5};
        TreeNode result = ref.constructMaximumBinaryTree(num);


    }
}

class Solution {

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return helper(nums, 0, nums.length - 1);
    }

    //max_index denotes the index of the maximum number in range [left, right]
    public TreeNode helper(int[] nums, int left, int right) {
        if (left > right)
            return null;

        int max_index = left;
        for (int i = left; i <= right; i++) {

            //root에 들어갈 6의 위치를 찾게 된다.
            if (nums[i] > nums[max_index])
                max_index = i;
        }

        TreeNode root = new TreeNode(nums[max_index]);
        root.left = helper(nums, left, max_index - 1);
        root.right = helper(nums, max_index + 1, right);
        return root;
    }

}


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

```

