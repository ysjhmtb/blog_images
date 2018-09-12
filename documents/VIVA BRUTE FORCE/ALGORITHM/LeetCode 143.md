> [143. Reorder List](https://leetcode.com/problems/reorder-list/description/)   
>
> <br>
>
> Given a singly linked list *L*: *L*0→*L*1→…→*L**n*-1→*L*n,
> reorder it to: *L*0→*L**n*→*L*1→*L**n*-1→*L*2→*L**n*-2→…
>
> You may **not** modify the values in the list's nodes, only nodes itself may be changed.
>
> **Example 1:**
>
> ```
> Given 1->2->3->4, reorder it to 1->4->2->3.
> ```
>
> **Example 2:**
>
> ```
> Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
> ```

<br>

[Java Solution using list and two pointers](https://leetcode.com/problems/reorder-list/discuss/169035/Java-Solution-using-list-and-two-pointers) 의 알고리즘을 학습. 

<br>

```java
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}


public class HelloWorld {

    public static void main(String[] args) {

        ListNode l1 = new ListNode(1);
        ListNode l2 = new ListNode(2);
        ListNode l3 = new ListNode(3);
        ListNode l4 = new ListNode(4);
        ListNode l5 = new ListNode(5);

        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l4.next = l5;

        Solution ref = new Solution();
        ref.reorderList(l1);

        ListNode result = l1;

        while (result != null) {
            System.out.print(result.val + ", ");
            result = result.next;
        }


    }


}


class Solution {

    //head: 1 - 2 - 3 - 4 - 5
    public void reorderList(ListNode head) {

        if (head == null)
            return;

        List<ListNode> list = new ArrayList<>();

        //node = 2
        ListNode node = head.next;

        // list : 2 3 4 5
        while (node != null) {
            list.add(node);
            node = node.next;
        }

        //i = 0, j = 3
        int i = 0, j = list.size() - 1;
        ListNode tmp = head;

        //첫번째 루프만 보면
        //1 - 5 - 2 로 구성된다.
        //temp가 head를 참조한 후에 (2,3,4,5)를 담고 있는 리스트의
        //맨 뒤에 위치한 5를 next로 참조하고, temp로 5를 참조한다.
        //이후 리스트의 맨 앞에 위치한 2를 next로 참조하고, temp로 2를 참조한다.
        //이의 반복이다.
        while (j > i) {
            tmp.next = list.get(j);
            tmp = tmp.next;
            tmp.next = list.get(i);
            tmp = tmp.next;
            i++;
            j--;
        }

        //리스트의 길이가 홀수라면 실행될 것이다.
        if (i == j) {
            tmp.next = list.get(i);
            tmp = tmp.next;
        }

        tmp.next = null;
    }
}



```

<br>

위의 알고리즘을 JavaScript로 옮겨보았다.

```javascript
const ListNode = class {

    constructor(val) {
        this.val = val;
        let next = null;
    }
};


const Solution = class {

    reorderList(head) {

        if (head == null)
            return;

        let list = [];

        let node = head.next;

        while (node != null) {
            list.push(node);
            node = node.next;
        }

        let i = 0;
        let j = list.length - 1;
        let temp = head;

        while (j > i) {
            temp.next = list[j];
            temp = temp.next;
            temp.next = list[i];
            temp = temp.next;
            i++;
            j--;
        }

        if (i == j) {
            temp.next = list[i];
            temp = temp.next;
        }
        temp.next = null;

    }
};


let l1 = new ListNode(1);
let l2 = new ListNode(2);
let l3 = new ListNode(3);
let l4 = new ListNode(4);
let l5 = new ListNode(5);

l1.next = l2;
l2.next = l3;
l3.next = l4;
l4.next = l5;

let ref = new Solution();
ref.reorderList(l1);

let result = l1;

while(result != null){
    console.log(result.val + ", ");
    result = result.next;
}
```

