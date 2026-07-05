#include <stddef.h>
#include <limits.h>
#include "solution.h"

int thirdMax(const int* nums, int numsSize) {
    long max1 = LONG_MIN;
    long max2 = LONG_MIN;
    long max3 = LONG_MIN;
    size_t distinct_count = 0;

    for (size_t i = 0; (int) i < numsSize; ++i) {
        if (nums[i] == max1 || nums[i] == max2 || nums[i] == max3) {
            continue;
        }
        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
            distinct_count++;
        } else if (nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
            distinct_count++;
        } else if (nums[i] > max3) {
            max3 = nums[i];
            distinct_count++;
        }
    }
    return distinct_count > 2 ? (int) max3 : (int) max1;
}
