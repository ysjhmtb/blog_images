> 814. [Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/description/)
>
> We are given the head node `root` of a binary tree, where additionally every node's value is either a 0 or a 1.
>
> Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
>
> (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
>
> ```
> Example 1:
> Input: [1,null,0,0,1]
> Output: [1,null,0,null,1]
>  
> Explanation: 
> Only the red nodes satisfy the property "every subtree not containing a 1".
> The diagram on the right represents the answer.
> 
> ```
>
> <img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png">
>
> ```
> Example 2:
> Input: [1,0,1,0,0,0,1]
> Output: [1,null,1,null,1]
> ```
>
> <img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png">
>
> ```
> Example 3:
> Input: [1,1,0,1,1,0,1,0]
> Output: [1,1,0,1,1,null,1]
> ```
>
> <img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png">
>
> **Note:**
>
> - The binary tree will have at most `100 nodes`.
> - The value of each node will only be `0` or `1`.

<br>

[[C++/Java/Python]  Self-Explaining Solution and 2-lines](https://leetcode.com/problems/binary-tree-pruning/discuss/122730/C++JavaPython-Self-Explaining-Solution-and-2-lines) 의 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        TreeNode node1 = new TreeNode(1);
        TreeNode node3 = new TreeNode(0);
        TreeNode node4 = new TreeNode(0);
        TreeNode node5 = new TreeNode(1);

        node1.right = node3;
        node3.left = node4;
        node3.right = node5;

        TreeNode root = ref.pruneTree(node1);
    }
}

class Solution {
    
    public TreeNode pruneTree(TreeNode root) {
        if (root == null)
            return null;
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);
        if (root.left == null && root.right == null && root.val == 0)
            return null;
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

<br>

