// Created by miracoly at 2026/07/07 21:22
// leetgo: 1.4.17
// https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MinStack {
 public:
  MinStack() {
    data = make_unique<int[]>(INITIAL_CAPACITY);
    min_stack = make_unique<int[]>(INITIAL_CAPACITY);
  }

  void push(int value) {
    if (empty()) {
      min_stack.get()[min_size++] = value;
    } else if (value <= getMin()) {
      if (min_size == min_capacity) {
        grow(min_stack, min_size, min_capacity);
      }
      min_stack.get()[min_size++] = value;
    }

    if (size == capacity) {
      grow(data, size, capacity);
    }
    data.get()[size++] = value;
  }

  void pop() {
    throw_if_empty();
    if (top() == getMin()) {
      --min_size;
    }
    --size;
  }

  int top() {
    throw_if_empty();
    return data.get()[size - 1];
  }

  int getMin() {
    throw_if_empty();
    return min_stack.get()[min_size - 1];
  }

 private:
  static constexpr size_t INITIAL_CAPACITY{10};

  size_t size{0};
  size_t capacity{INITIAL_CAPACITY};
  std::unique_ptr<int[]> data;

  size_t min_size{0};
  size_t min_capacity{INITIAL_CAPACITY};
  std::unique_ptr<int[]> min_stack;

  bool empty() { return size == 0; }

  void grow(unique_ptr<int[]>& ptr, size_t size, size_t& capacity) {
    capacity *= 2;
    unique_ptr<int[]> new_ptr = make_unique<int[]>(capacity);
    std::copy_n(ptr.get(), size, new_ptr.get());
    ptr = std::move(new_ptr);
  }

  void throw_if_empty() {
    if (size == 0) throw std::logic_error("stack is empty");
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> method_names;
  LeetCodeIO::scan(cin, method_names);

  MinStack* obj;
  const unordered_map<string, function<void()>> methods = {
      {"MinStack",
       [&]() {
         cin.ignore();
         obj = new MinStack();
         out_stream << "null,";
       }},
      {"push",
       [&]() {
         int value;
         LeetCodeIO::scan(cin, value);
         cin.ignore();
         obj->push(value);
         out_stream << "null,";
       }},
      {"pop",
       [&]() {
         cin.ignore();
         obj->pop();
         out_stream << "null,";
       }},
      {"top",
       [&]() {
         cin.ignore();
         LeetCodeIO::print(out_stream, obj->top());
         out_stream << ',';
       }},
      {"getMin",
       [&]() {
         cin.ignore();
         LeetCodeIO::print(out_stream, obj->getMin());
         out_stream << ',';
       }},
  };
  cin >> ws;
  out_stream << '[';
  for (auto&& method_name : method_names) {
    cin.ignore(2);
    methods.at(method_name)();
  }
  cin.ignore();
  out_stream.seekp(-1, ios_base::end);
  out_stream << ']';
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
