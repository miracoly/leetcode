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

    *returnSize = 0;
    for (size_t i = 1; (int) i <= numsSize; ++i) {
        if (!included[i])
            (*returnSize)++;
    }
    int* result = calloc(*returnSize, sizeof(*nums));

    size_t k = 0;
    for (size_t i = 1; (int) i <= numsSize; ++i) {
        if (!included[i]) {
            result[k] = (int) i;
            k++;
        }
    }

    return result;
}
