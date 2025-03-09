package org.example;

import static org.assertj.core.api.Assertions.assertThat;

import org.junit.jupiter.api.Test;

class SolutionTest {

    @Test
    void testAllStudentsEat() {
        int[] students = {1, 1, 0, 0};
        int[] sandwiches = {0, 1, 0, 1};

        var solution = new Solution();
        assertThat(solution.countStudents(students, sandwiches)).isZero();
    }

    @Test
    void testSomeStudentsUnableToEat() {
        int[] students = {1, 1, 1, 0, 0, 1};
        int[] sandwiches = {1, 0, 0, 0, 1, 1};

        var solution = new Solution();
        assertThat(solution.countStudents(students, sandwiches)).isEqualTo(3);
    }

}