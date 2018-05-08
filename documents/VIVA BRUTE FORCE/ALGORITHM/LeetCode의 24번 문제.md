



<br>

> 24. Swap Nodes in Pairs
>
> Given a linked list, swap every two adjacent nodes and return its head.
>
> **Example:**
>
> ```
> Given 1->2->3->4, you should return the list as 2->1->4->3.
> ```
>
> **Note:**
>
> - Your algorithm should use only constant extra space.
> - You may **not** modify the values in the list's nodes, only nodes itself may be changed.
>
> https://leetcode.com/problems/swap-nodes-in-pairs/description/



<br>

이 [링크](https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11312/Python-concise-iterative-and-recursive-solutions.) 를 통해 다음과 같은 파이썬 코드를 학습하였다.

<br>

```Python
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head):
        if head and head.next:
            tmp = head.next
            head.next = self.swapPairs(tmp.next)
            tmp.next = head
            return tmp
        return head



node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = None

ref = Solution()
head = ref.swapPairs(node1)

while (head != None):
    print(head.val)
    head = head.next
```



<br>

배운 내용을 바탕으로 자바 코드를 아래와 같이 작성하였다.

<br>

```Java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        ListNode node4 = new ListNode(4, null);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);

        ListNode head = ref.swapPairs(node1);
        while (head != null) {
            System.out.println(head.value);
            head = head.next;
        }


    }
}

class ListNode {

    int value;
    ListNode next;

    public ListNode(int value, ListNode next) {
        this.value = value;
        this.next = next;
    }
}

class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head != null && head.next != null) {
            ListNode temp = head.next;
            head.next = this.swapPairs(temp.next);
            temp.next = head;
            return temp;
        }
        return head;
    }
}
```

<br>