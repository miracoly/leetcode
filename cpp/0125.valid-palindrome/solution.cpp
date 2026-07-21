// Created by miracoly at 2026/07/21 22:06
// leetgo: 1.4.17
// https://leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  bool isPalindrome(string s) {
    int l{0};
    int r{static_cast<int>(s.size()) - 1};
    while (l < r) {
      const auto lc = static_cast<unsigned char>(s[static_cast<size_t>(l)]);
      const auto rc = static_cast<unsigned char>(s[static_cast<size_t>(r)]);
      if (!std::isalnum(lc)) {
        ++l;
        continue;
      }
      if (!std::isalnum(rc)) {
        --r;
        continue;
      }
      if (std::tolower(lc) != std::tolower(rc)) return false;
      ++l;
      --r;
    }
    return true;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution* obj = new Solution();
  auto res = obj->isPalindrome(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
