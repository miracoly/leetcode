package org.example;

class MyLinkedList {
    private Node head;
    private Node tail;
    private int length;

    public MyLinkedList() {
        length = 0;
    }

    public int get(int index) {
        final var node = _get(index);
        return node == null ? -1 : node.val;
    }

    public void addAtHead(int val) {
        final var newHead = new Node(val, null, head);
        if (head != null) {
            head.prev = newHead;
        }
        head = newHead;
        if (length == 0) tail = head;
        length++;
    }

    public void addAtTail(int val) {
        if (length == 0) {
            addAtHead(val);
            return;
        }
        final var newTail = new Node(val, tail, null);
        tail.next = newTail;
        tail = newTail;
        length++;
    }

    public void addAtIndex(int index, int val) {
        if (index < 0) return;
        if (index > length) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == length) {
            addAtTail(val);
            return;
        }

        final Node cur = _get(index - 1);
        if (cur == null) return;
        final var node = new Node(val, cur, cur.next);
        cur.next = node;
        node.next.prev = node;
        length++;
    }

    public void deleteAtIndex(int index) {
        final var node = _get(index);
        if (node == null) return;

        final var prev = node.prev;
        final var next = node.next;
        if (prev == null) {
            head = next;
        } else {
            prev.next = next;
        }
        if (next == null) {
            tail = prev;
        } else {
            next.prev = prev;
        }

        length--;
    }

    private Node _get(int index) {
        if (index < 0 || index >= length) return null;

        Node cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur.next;
        }
        return cur;
    }
}

class Node {
    int val;
    Node prev;
    Node next;

    public Node(int val, Node prev, Node next) {
        this.val = val;
        this.prev = prev;
        this.next = next;
    }
}
