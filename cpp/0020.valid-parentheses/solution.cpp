// Created by miracoly at 2026/07/07 19:44
// leetgo: 1.4.17
// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  bool isValid(string s) {
    std::stack<char, std::vector<char>> stack;
    for (const char c : s) {
      if (stack.empty() && !is_open(c)) return false;
      if (is_open(c)) {
        stack.push(c);
        continue;
      }
      if (get_closing(stack.top()) == c) {
        stack.pop();
        continue;
      }
      return false;
    }
    return stack.empty();
  }

 private:
  static constexpr bool is_open(char c) {
    return c == '(' || c == '[' || c == '{';
  }
  static constexpr char get_closing(char c) {
    switch (c) {
      case '(': return ')';
      case '[': return ']';
      case '{': return '}';
    }
    std::unreachable();
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution* obj = new Solution();
  auto res = obj->isValid(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
