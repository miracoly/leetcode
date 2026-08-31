// Created by miracoly at 2026/07/22 20:41
// leetgo: 1.4.17
// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  int climbStairs(int n) {
    assert(n > 0);
    std::unordered_map<int, int> cache;
    cache.reserve(static_cast<std::size_t>(n));
    return memoize(n, cache);
  }

 private:
  int memoize(int n, std::unordered_map<int, int>& cache) {
    assert(n > 0);
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (auto it = cache.find(n); it != cache.end()) return it->second;
    cache[n] = memoize(n - 1, cache) + memoize(n - 2, cache);
    return cache[n];
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution* obj = new Solution();
  auto res = obj->climbStairs(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
