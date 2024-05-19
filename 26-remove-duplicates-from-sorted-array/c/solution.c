#include <stddef.h>
#include "solution.h"

int removeDuplicates(int* nums, int numsSize) {
    int k = 0;
    for (size_t i = 1; (int) i < numsSize; ++i) {
        if (nums[k] != nums[i]) {
            nums[++k] = nums[i];
        }
    }
    return k;
}
