// Created by miracoly at 2026/07/06 23:20
// leetgo: 1.4.17
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
#include <limits>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    std::unordered_set<int> all;
    all.reserve(nums.size());
    for (const auto n : nums) {
      all.insert(n);
    }
    int res{0};
    for (const auto n : all) {
      if (all.contains(n - 1)) continue;
      res = std::max(count_consecutive(n, all), res);
    }
    return res;
  }

 private:
  static int count_consecutive(int start, const std::unordered_set<int>& all) {
    int count{0};
    while (all.contains(start)) {
      ++count;
      if (start == std::numeric_limits<int>::max()) break;
      ++start;
    }
    return count;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution* obj = new Solution();
  auto res = obj->longestConsecutive(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
