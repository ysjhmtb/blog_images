package com.company;

/*
https://leetcode.com/problems/implement-queue-using-stacks/
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
1) push push push
3
2
1 <- front
<stack 1>
2) pop
1 <- front (X)
2
3
<stack 2>
3) push push
5
4 <- front
<stack 1>
2
3
<stack 2>
4) peek
return front
Accepted
 */

import java.util.Stack;

public class MyQueue {
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();
    private int front;

    /**
     * Initialize your data structure here.
     */
    public MyQueue() {

    }

    /**
     * Push element x to the back of queue.
     */
    // O(1)
    public void push(int x) {
        if (s1.empty())
            front = x;
        s1.push(x);

    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    // O(N)
    public int pop() {
        if (s2.empty()) {
            while (!s1.empty())
                s2.push(s1.pop());
        }
        return s2.pop();
    }

    /**
     * Get the front element.
     */
    // O(1)
    public int peek() {
        if (!s2.empty())
            return s2.peek();
        return front;
    }

    /**
     * Returns whether the queue is empty.
     */
    // O(1)
    public boolean empty() {
        return s1.empty() && s2.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
