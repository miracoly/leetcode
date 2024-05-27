#include <stddef.h>
#include "solution.h"

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    if (!nums || !returnSize) return NULL;
    size_t k = numsSize - 1;
    for (size_t i = 0; (int) i < numsSize; ++i) {
        if (i == k) break;
        if (nums[i] % 2 != 0) {
            const int tmp = nums[k];
            nums[k--] = nums[i];
            nums[i--] = tmp;
        }
    }
    *returnSize = numsSize;
    return nums;
}
