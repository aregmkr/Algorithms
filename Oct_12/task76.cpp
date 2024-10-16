#include <iostream>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/minimum-window-substring/description/

std::string minWindow(std::string s, std::string t) {
    std::vector<std::string> tmp;
    for (int i = 0; i < s.size(); ++i) {
        int j = i;
        int len = 0;
        int left = -1;
        while(j < s.size()) {
            std::string temporary;
            for (int k = 0; k < t.size(); ++k) {
                if (s[j] == t[k]) {
                    if (left == -1) {
                        left = j;
                    }
                    ++len;
                    break;
                }
            }
            if (len >= t.size()) {
                std::string sub = s.substr(left, j - left + 1);
                if (temporary != sub) {
                    tmp.push_back(sub);
                    temporary = sub;
                break;
            }
            }
            ++j;
        }
    }
    if (tmp.empty()) {
        return "";
    }
    
    for (const std::string& item : tmp) {
        std::cout << item << std::endl;
    }   
    return tmp[0];
}

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string res = minWindow(s, t);
    std::cout << "Result: " << res << std::endl;
    return 0;
}


// Given two tmp s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.