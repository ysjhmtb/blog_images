<br>

> 94. Binary Tree Inorder Traversal
>
> Given a binary tree, return the *inorder* traversal of its nodes' values.
>
> **Example:**
>
> ```
> Input: [1,null,2,3]
>    1
>     \
>      2
>     /
>    3
> 
> Output: [1,3,2]
> ```
>
> **Follow up:** Recursive solution is trivial, could you do it iteratively?

<br><hr>

<br>

[Java recursive and iterative](https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/133575/Java-recursive-and-iterative) 의 다음 알고리즘을 학습하였다.

우선 재귀를 사용한 방법이 있고,

```Java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        TreeNode n3 = new TreeNode(3);

        n1.left = null;
        n1.right = n2;
        n2.left = n3;

        List<Integer> res = ref.inorderTraversal(n1);
        System.out.println(res);    // 1 3 2


    }
}


/*
Input: [1,null,2,3]
   1
    \
     2
    /
   3


Output: [1,3,2]


*/

class Solution {

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        printInOrder(root, res);
        return res;
    }

    private void printInOrder(TreeNode root, List<Integer> res) {
        if (root == null)
            return;
        printInOrder(root.left, res);
        res.add(root.val);
        printInOrder(root.right, res);
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

자료구조 덱을 사용한 반복적인 방법이 있다.

```Java

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        Deque<TreeNode> s = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();
        while (true) {
            if (root != null) {
                s.push(root);
                root = root.left;
            } else {
                if (s.isEmpty())
                    return res;
                root = s.pop();
                res.add(root.val);
                root = root.right;
            }
        }
    }

}
```

<br><br>

