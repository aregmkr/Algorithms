#include <iostream>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/minimum-window-substring/description/

std::string minWindow(std::string s, std::string t) {
    std::vector<std::string> tmp;
    int i = 0;
    while(i < s.size()){
        int j = 0;
        int len = 0;
        int left = 0;
        while(j < t.size() && i < s.size()) {
            if (s[i] == t[j]) {
                if (len == 0) { 
                    left = i;
                }
                ++j;
                ++len;
            }
            ++i;
        }   
        if (len == t.size()) {
            std::string sub = s.substr(left, i - left);
            tmp.push_back(sub);
        }
        ++i;
    }
    return (tmp.empty()) ? "" : *std::min_element(tmp.begin(), tmp.end());
}

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string res = minWindow(s, t);
    std::cout << "Result: " << res << std::endl;
    return 0;
}


// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.