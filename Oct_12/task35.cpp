#include <iostream>
#include <vector>

// https://leetcode.com/problems/search-insert-position/description/?envType=problem-list-v2&envId=array

int searchInsert(std::vector<int>& nums, int target) {
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (nums[mid] == target) {
            return mid;  
        } else if (nums[mid] < target) {
            i = mid + 1;  
        } else {
            j = mid - 1;
        }
    }
    return i; 
}


// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.