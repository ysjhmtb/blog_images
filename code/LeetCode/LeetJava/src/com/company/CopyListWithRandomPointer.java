package com.company;


/*
https://leetcode.com/problems/copy-list-with-random-pointer/

Accepted

time complexity O(N)
 */

import java.util.HashMap;
import java.util.Map;

class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {
    }

    public Node(int _val, Node _next, Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


public class CopyListWithRandomPointer {
    Map<Node, Node> visited = new HashMap<>();

    public Node getClonedNode(Node node) {
        if (node != null) {
            if (this.visited.containsKey(node)) {
                return this.visited.get(node);
            } else {
                this.visited.put(node, new Node(node.val, null, null));
                return this.visited.get(node);
            }
        }
        return null;
    }

    public Node copyRandomList(Node head) {
        if (head == null)
            return null;

        Node oldnode = head;
        Node newnode = this.getClonedNode(oldnode);

        while (oldnode != null) {
            newnode.random = this.getClonedNode(oldnode.random);
            newnode.next = this.getClonedNode(oldnode.next);
            oldnode = oldnode.next;
            newnode = newnode.next;
        }
        return this.visited.get(head);
    }
}
