
#include "main.hpp"
#include <gtest/gtest.h>

TEST(SortColorsTest, Example1) {
  Solution sol;
  std::vector<int> nums = {2, 0, 2, 1, 1, 0};
  sol.sortColors(nums);
  std::vector<int> expected = {0, 0, 1, 1, 2, 2};
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, Example2) {
  Solution sol;
  std::vector<int> nums = {2, 0, 1};
  sol.sortColors(nums);
  std::vector<int> expected = {0, 1, 2};
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, AlreadySorted) {
  Solution sol;
  std::vector<int> nums = {0, 0, 1, 1, 2, 2};
  sol.sortColors(nums);
  std::vector<int> expected = {0, 0, 1, 1, 2, 2};
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, AllSameColor) {
  Solution sol;
  std::vector<int> nums = {1, 1, 1, 1};
  sol.sortColors(nums);
  std::vector<int> expected = {1, 1, 1, 1};
  EXPECT_EQ(nums, expected);
}

TEST(SortColorsTest, SingleElement) {
  Solution sol;
  std::vector<int> nums = {2};
  sol.sortColors(nums);
  std::vector<int> expected = {2};
  EXPECT_EQ(nums, expected);
}
