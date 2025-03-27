package org.example;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.*;

class MyStackTest {

    @Test
    void testMyStackOperations() {
        MyStack myStack = new MyStack();

        myStack.push(1);
        myStack.push(2);

        // Check top element (should be 2)
        assertThat(myStack.top()).isEqualTo(2);

        // Pop top element (should return 2)
        assertThat(myStack.pop()).isEqualTo(2);

        // Check if stack is empty (should be false)
        assertThat(myStack.empty()).isFalse();
    }
}
