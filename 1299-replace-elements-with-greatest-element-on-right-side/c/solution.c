#include <stddef.h>
#include "solution.h"

int* replaceElements(int* arr, int arrSize, int* returnSize) {
    if (!arr || arrSize < 1) return NULL;

    int current_max = -1;
    for (size_t i = arrSize; i > 0; --i) {
        const size_t j = i - 1;
        const int tmp = arr[j];
        arr[j] = current_max;
        current_max = tmp > current_max ? tmp : current_max;
    }
    *returnSize = arrSize;
    return arr;
}
