#include <stddef.h>
#include "solution.h"

int heightChecker(const int* heights, int heightsSize) {
    size_t counter[101] = {0};
    for (size_t i = 0; (int) i < heightsSize; ++i) {
        counter[heights[i]]++;
    }

    size_t k = 0;
    size_t result = 0;
    for (size_t i = 0; (int) i < heightsSize; ++i) {
        while (!counter[k])
            k++;
        if (heights[i] != (int) k)
            result++;
        counter[k]--;
    }

    return (int) result;
}
