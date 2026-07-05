#include <stdlib.h>
#include "solution.h"

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int included[numsSize + 1];
    for (size_t i = 0; (int) i <= numsSize; ++i) {
        included[i] = 0;
    }
    for (size_t i = 0; (int) i < numsSize; ++i) {
        included[nums[i]] = 1;
    }

    int* result = calloc(numsSize, sizeof(*nums));

    *returnSize = 0;
    for (size_t i = 1; (int) i <= numsSize; ++i) {
        if (!included[i]) {
            result[*returnSize] = (int) i;
            (*returnSize)++;
        }
    }

    return result;
}
