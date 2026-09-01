// Created by miracoly at 2026/09/01 21:35
// leetgo: 1.4.17
// https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    if (!head) return false;
    ListNode* slow{head};
    ListNode* fast{head};
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) return true;
    }
    return false;
  }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode* head;
  LeetCodeIO::scan(cin, head);
  int pos;
  LeetCodeIO::scan(cin, pos);

  Solution* obj = new Solution();
  auto res = obj->hasCycle(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
