// Created by miracoly at 2026/07/08 19:50
// leetgo: 1.4.17
// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
#include "LC_IO.h"

using namespace std;

// @lc code=begin

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temp) {
    vector<int> res(temp.size());
    vector<int> past;
    past.reserve(temp.size());
    const auto n = static_cast<int>(temp.size());
    for (int i = 0; i < n; ++i) {
      while (!past.empty() && temp[static_cast<size_t>(past.back())] <
                                  temp[static_cast<size_t>(i)]) {
        res[static_cast<size_t>(past.back())] = i - past.back();
        past.pop_back();
      }
      past.push_back(i);
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> temperatures;
  LeetCodeIO::scan(cin, temperatures);

  Solution* obj = new Solution();
  auto res = obj->dailyTemperatures(temperatures);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
