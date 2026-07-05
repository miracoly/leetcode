#include "solution.h"
#include "uthash.h"

bool validMountainArray(const int* arr, int arrSize) {
    if (!arr || arrSize < 3) return false;
    if (arr[0] >= arr[1]) return false;
    bool is_falling = false;
    for (size_t i = 1; (int) i < arrSize; ++i) {
        if (arr[i - 1] == arr[i] || (is_falling && arr[i - 1] < arr[i])) return false;
        else if (!is_falling && arr[i - 1] > arr[i])
            is_falling = true;
    }

    return is_falling;
}
