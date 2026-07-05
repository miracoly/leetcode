// Created by miracoly at 2026/07/05 16:04
// leetgo: 1.4.17
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
#include "LC_IO.h"

using namespace std;

// @lc code=begin

class Solution {
 public:
  vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> grouped;
    for (const auto& s : strs) {
      auto sorted = s;
      sort(sorted.begin(), sorted.end());
      grouped[sorted].push_back(s);
    }
    vector<vector<string>> res;
    res.reserve(grouped.size());
    for (const auto& [_, val] : grouped) {
      res.push_back(std::move(val));
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> strs;
  LeetCodeIO::scan(cin, strs);

  Solution* obj = new Solution();
  auto res = obj->groupAnagrams(strs);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
