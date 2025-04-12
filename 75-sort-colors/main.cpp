#include "main.hpp"
#include "../debug.hpp"
#include <cstddef>

using namespace std;

void Solution::sortColors(vector<int> &nums) {
  array<int, 3> bucket{};

  for (int color : nums) {
    bucket[static_cast<size_t>(color)]++;
  }

  size_t i{0};
  for (size_t j{0}; j < bucket.size(); j++) {
    for (int k{0}; k < bucket[j]; k++) {
      nums[i] = static_cast<int>(j);
      i++;
    }
  }
};
