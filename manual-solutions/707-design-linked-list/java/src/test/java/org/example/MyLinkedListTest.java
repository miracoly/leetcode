package org.example;

import static org.assertj.core.api.Assertions.assertThat;

import org.junit.jupiter.api.Test;

class MyLinkedListTest {

    @Test
    void test1() {
        // ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
        // [[],[1],[3],[1,2],[1],[1],[1]]
        final var list = new MyLinkedList();
        list.addAtHead(1);
        list.addAtTail(3);
        list.addAtIndex(1, 2);
        final var i1 = list.get(1);
        assertThat(i1).isEqualTo(2);
        list.deleteAtIndex(1);
        final var i2 = list.get(1);
        assertThat(i2).isEqualTo(3);
    }


    @Test
    void test2() {
        MyLinkedList linkedList = new MyLinkedList();

        // ["MyLinkedList"]
        // Initial list: []

        // ["addAtHead",7]
        linkedList.addAtHead(7);
        assertThat(linkedList.get(0)).isEqualTo(7); // [7]

        // ["addAtHead",2]
        linkedList.addAtHead(2);
        assertThat(linkedList.get(0)).isEqualTo(2);
        assertThat(linkedList.get(1)).isEqualTo(7); // [2,7]

        // ["addAtHead",1]
        linkedList.addAtHead(1);
        assertThat(linkedList.get(0)).isEqualTo(1);
        assertThat(linkedList.get(1)).isEqualTo(2);
        assertThat(linkedList.get(2)).isEqualTo(7); // [1,2,7]

        // ["addAtIndex",3,0]
        linkedList.addAtIndex(3, 0);
        assertThat(linkedList.get(0)).isEqualTo(1);
        assertThat(linkedList.get(1)).isEqualTo(2);
        assertThat(linkedList.get(2)).isEqualTo(7);
        assertThat(linkedList.get(3)).isEqualTo(0); // [1,2,7,0]

        // ["deleteAtIndex",2]
        linkedList.deleteAtIndex(2);
        assertThat(linkedList.get(0)).isEqualTo(1);
        assertThat(linkedList.get(1)).isEqualTo(2);
        assertThat(linkedList.get(2)).isEqualTo(0); // [1,2,0]

        // ["addAtHead",6]
        linkedList.addAtHead(6);
        assertThat(linkedList.get(0)).isEqualTo(6);
        assertThat(linkedList.get(1)).isEqualTo(1);
        assertThat(linkedList.get(2)).isEqualTo(2);
        assertThat(linkedList.get(3)).isEqualTo(0); // [6,1,2,0]

        // ["addAtTail",4]
        linkedList.addAtTail(4);
        assertThat(linkedList.get(0)).isEqualTo(6);
        assertThat(linkedList.get(1)).isEqualTo(1);
        assertThat(linkedList.get(2)).isEqualTo(2);
        assertThat(linkedList.get(3)).isEqualTo(0);
        assertThat(linkedList.get(4)).isEqualTo(4); // [6,1,2,0,4]

        // ["get",4] -> Expected output: 4
        assertThat(linkedList.get(4)).isEqualTo(4);

        // ["addAtHead",4]
        linkedList.addAtHead(4);
        assertThat(linkedList.get(0)).isEqualTo(4);
        assertThat(linkedList.get(1)).isEqualTo(6);
        assertThat(linkedList.get(2)).isEqualTo(1);
        assertThat(linkedList.get(3)).isEqualTo(2);
        assertThat(linkedList.get(4)).isEqualTo(0);
        assertThat(linkedList.get(5)).isEqualTo(4); // [4,6,1,2,0,4]

        // ["addAtIndex",5,0]
        linkedList.addAtIndex(5, 0);
        assertThat(linkedList.get(0)).isEqualTo(4);
        assertThat(linkedList.get(1)).isEqualTo(6);
        assertThat(linkedList.get(2)).isEqualTo(1);
        assertThat(linkedList.get(3)).isEqualTo(2);
        assertThat(linkedList.get(4)).isEqualTo(0);
        assertThat(linkedList.get(5)).isEqualTo(0);
        assertThat(linkedList.get(6)).isEqualTo(4); // [4,6,1,2,0,0,4]

        // ["addAtHead",6]
        linkedList.addAtHead(6);
        assertThat(linkedList.get(0)).isEqualTo(6);
        assertThat(linkedList.get(1)).isEqualTo(4);
        assertThat(linkedList.get(2)).isEqualTo(6);
        assertThat(linkedList.get(3)).isEqualTo(1);
        assertThat(linkedList.get(4)).isEqualTo(2);
        assertThat(linkedList.get(5)).isEqualTo(0);
        assertThat(linkedList.get(6)).isEqualTo(0);
        assertThat(linkedList.get(7)).isEqualTo(4); // [6,4,6,1,2,0,0,4]
    }

    @Test
    void testMyLinkedListCase2() {
        MyLinkedList linkedList = new MyLinkedList();

        // ["MyLinkedList"]
        // Initial list: []

        // ["addAtHead",1] -> [1]
        linkedList.addAtHead(1);
        assertThat(linkedList.get(0)).isEqualTo(1);

        // ["addAtTail",3] -> [1,3]
        linkedList.addAtTail(3);
        assertThat(linkedList.get(0)).isEqualTo(1);
        assertThat(linkedList.get(1)).isEqualTo(3);

        // ["addAtIndex",1,2] -> Insert 2 before index 1 -> [1,2,3]
        linkedList.addAtIndex(1, 2);
        assertThat(linkedList.get(0)).isEqualTo(1);
        assertThat(linkedList.get(1)).isEqualTo(2);
        assertThat(linkedList.get(2)).isEqualTo(3);

        // ["get",1] -> Expected output: 2
        assertThat(linkedList.get(1)).isEqualTo(2);

        // ["deleteAtIndex",0] -> Remove index 0 (1) -> [2,3]
        linkedList.deleteAtIndex(0);
        assertThat(linkedList.get(0)).isEqualTo(2);
        assertThat(linkedList.get(1)).isEqualTo(3);

        // ["get",0] -> Expected output: 2
        assertThat(linkedList.get(0)).isEqualTo(2);
    }
}