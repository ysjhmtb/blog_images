<br>

> 817. Linked List Components
>
> We are given `head`, the head node of a linked list containing **unique integer values**.
>
> We are also given the list `G`, a subset of the values in the linked list.
>
> Return the number of connected components in `G`, where two values are connected if they appear consecutively in the linked list.
>
> **Example 1:**
>
> ```
> Input: 
> head: 0->1->2->3
> G = [0, 1, 3]
> Output: 2
> Explanation: 
> 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
> ```
>
> **Example 2:**
>
> ```
> Input: 
> head: 0->1->2->3->4
> G = [0, 3, 1, 4]
> Output: 2
> Explanation: 
> 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
> ```
>
> **Note:**
>
> - If `N` is the length of the linked list given by `head`, `1 <= N <= 10000`.
> - The value of each node in the linked list will be in the range` [0, N - 1]`.
> - `1 <= G.length <= 10000`.
> - `G` is a subset of all values in the linked list.
>
> <br>
>
> https://leetcode.com/problems/linked-list-components/description/



<br><hr>

<br>

[java easy understand hashset solution](https://leetcode.com/problems/linked-list-components/discuss/130782/java-easy-understand-hashset-solution) 의 다음 알고리즘을 학습.

<br>

```java
import java.util.HashSet;
import java.util.Set;

public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        ListNode n1 = new ListNode(0);
        ListNode n2 = new ListNode(1);
        ListNode n3 = new ListNode(2);
        ListNode n4 = new ListNode(3);
        ListNode n5 = new ListNode(4);

        ListNode head = n1;
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;

        int[] G = new int[]{0, 3, 1, 4};
        int output = ref.numComponents(head, G);
        System.out.println(output);
    }
}

/*
head -> 0 -> 1 -> 2 -> 3 -> 4
G :  0 3 1 4

hs : 0 1 3 4
res : 0


1) if(hs에 0 && hs에 1)

2) if(hs에 1 && hs에 2 미포함)
    res : 1

3) if(hs에 2 미포함 && )

4) if(hs에 3 && hs에 4)

5) if(hs에 4 && hash.next == null)
    res : 2


return res

 */

class Solution {
    public int numComponents(ListNode head, int[] G) {
        if (head == null)
            return 0;
        Set hs = new HashSet<>();
        for (int i = 0; i < G.length; i++) {
            hs.add(G[i]);
        }
        int res = 0;
        while (head != null) {
            // just make sure when we need to add 1
            if (hs.contains(head.val) && (head.next == null || !hs.contains(head.next.val))) {
                res += 1;
            }
            head = head.next;
        }
        return res;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}


```



