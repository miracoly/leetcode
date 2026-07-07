// Created by miracoly at 2026/07/07 22:13
// leetgo: 1.4.17
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
#include <stack>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    std::stack<int, vector<int>> expr;
    for (const auto& s : tokens) {
      if (is_operator(s)) {
        const int operand_2 = expr.top();
        expr.pop();
        const int operand_1 = expr.top();
        expr.pop();
        const int result = get_operation(s)(operand_1, operand_2);
        expr.push(result);
      } else {
        expr.push(std::stoi(s));
      }
    }
    assert(expr.size() == 1);
    return expr.top();
  }

 private:
  static bool is_operator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
  }
  static function<int(int, int)> get_operation(const string& op) {
    assert(is_operator(op));
    switch (op[0]) {
      case '+': return std::plus<int>();
      case '-': return std::minus<int>();
      case '*': return std::multiplies<int>();
      case '/': return std::divides<int>();
    }
    std::unreachable();
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> tokens;
  LeetCodeIO::scan(cin, tokens);

  Solution* obj = new Solution();
  auto res = obj->evalRPN(tokens);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
