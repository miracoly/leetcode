// Created by miracoly at 2026/08/31 10:46
// leetgo: 1.4.17
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  int rob(vector<int>& nums) {
    unordered_map<int, int> cache;
    return rob(static_cast<int>(nums.size() - 1), cache, nums);
  }

 private:
  int rob(int i, unordered_map<int, int>& cache, const vector<int>& nums) {
    if (i < 0) return 0;
    if (const auto it = cache.find(i); it != cache.end()) {
      return it->second;
    };
    const std::size_t ui = static_cast<std::size_t>(i);
    const int res =
        std::max(nums[ui] + rob(i - 2, cache, nums), rob(i - 1, cache, nums));
    cache[i] = res;
    return res;
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
