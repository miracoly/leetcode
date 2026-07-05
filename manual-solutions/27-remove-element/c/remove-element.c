#include <stddef.h>
#include "remove-element.h"

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (size_t i = 0; (int) i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[k++] = nums[i];
        }
    }
    return k;
}
