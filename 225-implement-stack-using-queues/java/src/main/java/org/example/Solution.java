package org.example;

import java.util.LinkedList;
import java.util.Queue;

class MyStack {
    private Queue<Integer> queue;

    public MyStack() {
        this.queue = new LinkedList<>();
    }

    public void push(int x) {
        Queue<Integer> q2 = new LinkedList<>();
        q2.add(x);
        while (!queue.isEmpty()) {
            q2.add(queue.poll());
        }
        queue = q2;
    }

    public int pop() {
        return queue.isEmpty() ? -1 : queue.poll();
    }

    public int top() {
        return queue.isEmpty() ? -1 : queue.peek();
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}
