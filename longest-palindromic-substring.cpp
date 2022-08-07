#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int left = i - 1; 
            int right = i + 1;
            while (right < len && s[right] == s[i]) {
                right ++;
            }
            while (0 <= left && left < right && right < len && s[left] == s[right]) {
                left --; right ++;
            }
            if (right - left - 1 > ans.length()) {
                ans = s.substr(left + 1, right - left - 1);
            }
        }
        return ans;
    }
};
