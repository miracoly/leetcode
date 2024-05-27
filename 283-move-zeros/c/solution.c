#include <stddef.h>
#include "solution.h"

void moveZeroes(int* nums, int numsSize) {
    if (!nums || numsSize < 1) return;

    size_t k = 0;
    for (size_t i = 0; (int) i < numsSize; ++i) {
        if (nums[i]) {
            nums[k++] = nums[i];
        }
    }

    for (size_t i = k; (int) i < numsSize; ++i) {
        nums[i] = 0;
    }
}
