// Created by miracoly at 2026/08/31 10:46
// leetgo: 1.4.17
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
#include <algorithm>
#include <cstddef>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  int rob(vector<int>& nums) { return rob(0, nums); }

 private:
  int rob(int i, const vector<int>& nums) {
    if (i >= static_cast<int>(nums.size())) return 0;
    const std::size_t ui = static_cast<std::size_t>(i);
    return std::max(nums[ui] + rob(i + 2, nums), rob(i + 1, nums));
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution* obj = new Solution();
  auto res = obj->rob(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
