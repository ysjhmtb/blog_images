/*
https://leetcode.com/problems/merge-k-sorted-lists/

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6


Accepted
time complexity : N log(N)
 */

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class N23 {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode point = new ListNode(0);
        ListNode head = point;
        List<Integer> nodes = new ArrayList<>();
        for (ListNode node : lists) {
            while (node != null) {
                nodes.add(node.val);
                node = node.next;
            }
        }
        Collections.sort(nodes);
        for (int val : nodes) {
            point.next = new ListNode(val);
            point = point.next;
        }
        return head.next;
    }
}
