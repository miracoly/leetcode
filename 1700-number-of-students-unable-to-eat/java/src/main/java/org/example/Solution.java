package org.example;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Objects;

class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        var queue = new LinkedList<>(Arrays.stream(students).boxed().toList());
        var size = queue.size();

        if (size == 0) return 0;

        int i = 0;
        int count = 0;
        while (i < size) {
            if (count == queue.size()) return count;

            final var student = queue.poll();
            if (Objects.equals(student, sandwiches[i])) {
                count = 0;
                i++;
            } else {
                queue.add(student);
                count++;
            }
        }

        return size - i;
    }
}
