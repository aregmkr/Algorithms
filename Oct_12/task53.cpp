#include <iostream>
#include <vector>

// https://leetcode.com/problems/maximum-subarray/submissions/1420891551/?envType=problem-list-v2&envId=array

int maxSubArray(std::vector<int>& nums) {
    int max = nums[0];
    int res = nums[0];
    const int size = nums.size();
    for (int i = 1; i < size; ++i) {
        max = (nums[i] > nums[i] + max) ? nums[i] : nums[i] + max;
        res = (max > res) ? max : res;
    }   
    return res;
}

// Given an integer array nums, find the 
// subarray with the largest sum, and return its sum.