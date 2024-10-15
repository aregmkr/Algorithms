#include <iostream>
#include <vector>
#include <algorithm>

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
    }
    return (tmp.empty()) ? "" : *std::min_element(tmp.begin(), tmp.end());
}

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string res = minWindow(s, t);
    std::cout << "Result:  " << res << std::endl;
    return 0;
}

