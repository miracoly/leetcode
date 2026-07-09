// Created by miracoly at 2026/07/08 21:10
// leetgo: 1.4.17
// https://leetcode.com/problems/car-fleet/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Car {
  int pos;
  int speed;
  double time;

  auto operator<=>(const Car&) const = default;
};

class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;
    cars.reserve(position.size());
    for (size_t i{0}; i < position.size(); ++i) {
      const auto time = static_cast<double>(target - position[i]) / speed[i];
      cars.emplace_back(position[i], speed[i], time);
    }
    sort(cars.begin(), cars.end());

    int count{1};
    double time_leader{};
    bool first{true};
    for (const auto& c : cars | std::views::reverse) {
      if (first) {
        first = false;
        time_leader = c.time;
        continue;
      }

      if (c.time > time_leader) {
        count++;
        time_leader = c.time;
      }
    }

    return count;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int target;
  LeetCodeIO::scan(cin, target);
  vector<int> position;
  LeetCodeIO::scan(cin, position);
  vector<int> speed;
  LeetCodeIO::scan(cin, speed);

  Solution* obj = new Solution();
  auto res = obj->carFleet(target, position, speed);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
