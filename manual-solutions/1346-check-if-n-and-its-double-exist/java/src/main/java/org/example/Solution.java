package org.example;

import java.util.HashSet;

class Solution {
    public boolean checkIfExist(int[] arr) {
        final var map = HashSet.<Integer>newHashSet(100);

        for (int n : arr) {
            if (map.contains(n * 2)) {
                return true;
            }
            if (n % 2 == 0 && map.contains(n / 2)) {
                return true;
            }
            map.add(n);
        }

        return false;
    }
}
