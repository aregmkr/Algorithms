#include <iostream>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/sort-colors/description/

void sortColors(std::vector<int>& nums) {
    int max = *std::max_element(nums.begin(), nums.end());
    int min = *std::min_element(nums.begin(), nums.end());
    std::vector<int> count(max - min + 1, 0);
    std::vector<int> output(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        ++count[nums[i] - min];
    }
    for (int i = 1; i < max - min + 1; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
        output[--count[nums[i] - min]] = nums[i];
    }
    nums = output;
}




// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

