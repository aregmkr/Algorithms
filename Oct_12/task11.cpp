#include <iostream>
#include <vector>

//https://leetcode.com/problems/container-with-most-water/description/?envType=problem-list-v2&envId=array

int maxArea(std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    int max = 0;
    while(left < right) {
        int tmp = 0;
        if (arr[left] > arr[right]) {
            tmp = arr[right];
        } else {
            tmp = arr[left];
        }
        int area = tmp * (right - left);
        if (area > max) {
            max = area;
        }

        if (arr[left] < arr[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return max;
}


// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

