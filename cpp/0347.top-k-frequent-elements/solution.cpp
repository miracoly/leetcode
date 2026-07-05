// Created by miracoly at 2026/07/05 19:02
// leetgo: 1.4.17
// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
#include <debug.hpp>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Count {
  int num;
  int count;
};

struct Comp {
  bool operator()(const Count& a, const Count& b) const {
    return a.count < b.count;
  }
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for (const auto n : nums) {
      counts[n]++;
    }

    priority_queue<Count, vector<Count>, Comp> heap;
    for (const auto [num, count] : counts) {
      heap.push(Count{.num = num, .count = count});
    }

    vector<int> res;
    res.reserve(static_cast<size_t>(k));
    while (k--) {
      res.push_back(heap.top().num);
      heap.pop();
    }

    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution* obj = new Solution();
  auto res = obj->topKFrequent(nums, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
