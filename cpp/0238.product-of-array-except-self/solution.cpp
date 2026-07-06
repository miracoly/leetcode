// Created by miracoly at 2026/07/06 19:21
// leetgo: 1.4.17
// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<long long> left(nums.size());
    vector<long long> right(nums.size());
    std::exclusive_scan(nums.begin(), nums.end(), left.begin(), 1ll,
                        std::multiplies<long long>{});
    std::exclusive_scan(nums.rbegin(), nums.rend(), right.rbegin(), 1ll,
                        std::multiplies<long long>{});

    const int len = static_cast<int>(nums.size());
    for (int i = 0; i < len; ++i) {
      const auto ui = static_cast<size_t>(i);
      nums[ui] = static_cast<int>(left[ui] * right[ui]);
    }
    return nums;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution* obj = new Solution();
  auto res = obj->productExceptSelf(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
