// Created by miracoly at 2026/07/21 22:27
// leetgo: 1.4.17
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int l{0};
    int r{static_cast<int>(numbers.size()) - 1};
    const auto at = [&numbers](int idx) {
      return numbers[static_cast<std::size_t>(idx)];
    };
    const auto sum = [&at, &l, &r]() {
      return at(l) + at(r);
    };

    while (sum() != target) {
      if (sum() > target) {
        --r;
      } else {
        ++l;
      }
    }

    return vector<int>{l + 1, r + 1};
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> numbers;
  LeetCodeIO::scan(cin, numbers);
  int target;
  LeetCodeIO::scan(cin, target);

  Solution* obj = new Solution();
  auto res = obj->twoSum(numbers, target);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
