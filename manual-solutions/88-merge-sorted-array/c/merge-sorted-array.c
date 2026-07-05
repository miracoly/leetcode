#include <string.h>
#include "merge-sorted-array.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (!nums1 || !nums2 || nums1Size != m + n || nums2Size != n || !n) return;

    size_t i = m;
    size_t j = n;
    size_t k = m + n - 1;

    while (i && j) {
        if (nums1[i - 1] < nums2[j - 1]) {
            nums1[k--] = nums2[j-- - 1];
        } else {
            nums1[k--] = nums1[i-- - 1];
        }
    }

    while (j) {
        nums1[k--] = nums2[j-- - 1];
    }
}
