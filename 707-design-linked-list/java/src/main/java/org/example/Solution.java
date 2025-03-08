package org.example;

class MyLinkedList {
    private final Node preHead; // sentinel head
    private int size;

    public MyLinkedList() {
        preHead = new Node(0, null, new Node(0));      // dummy head
        size = 0;
    }

    public int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        Node cur = preHead.next;
        for (int i = 0; i < index; i++) {
            cur = cur.next;
        }
        return cur.val;
    }

    public void addAtHead(int val) {
        addAtIndex(0, val);
    }

    public void addAtTail(int val) {
        addAtIndex(size, val);
    }

    public void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        // Find the "previous" node (prev) where we will insert the new node
        Node prev = preHead;
        for (int i = 0; i < index; i++) {
            prev = prev.next;
        }
        Node next = prev.next;

        Node newNode = new Node(val, prev, next);

        prev.next = newNode;
        next.prev = newNode;

        size++;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        // Move to the node just before the node we want to delete
        Node prev = preHead;
        for (int i = 0; i < index; i++) {
            prev = prev.next;
        }
        Node toDelete = prev.next;
        Node next = toDelete.next;

        prev.next = next;
        next.prev = prev;

        size--;
    }

    // Inner Node class for our doubly linked list
    private static class Node {
        int val;
        Node prev;
        Node next;

        Node(int val) {
            this(val, null, null);
        }

        Node(int val, Node prev, Node next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }
}
