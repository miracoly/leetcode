// Created by miracoly at 2026/07/06 20:31
// leetgo: 1.4.17
// https://leetcode.com/problems/valid-sudoku/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<unsigned> rows(9);
    vector<unsigned> columns(9);
    vector<unsigned> boxes(9);
    for (unsigned r = 0; r < board.size(); ++r) {
      for (unsigned c = 0; c < board.size(); ++c) {
        if (!isdigit(static_cast<unsigned char>(board[r][c]))) continue;

        const unsigned bitmask = 1u << static_cast<unsigned>(board[r][c] - '0');
        const std::size_t b = (r / 3) * 3 + (c / 3);
        if (rows[r] & bitmask || columns[c] & bitmask || boxes[b] & bitmask)
          return false;
        rows[r] |= bitmask;
        columns[c] |= bitmask;
        boxes[b] |= bitmask;
      }
    }
    return true;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<char>> board;
  LeetCodeIO::scan(cin, board);

  Solution* obj = new Solution();
  auto res = obj->isValidSudoku(board);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
