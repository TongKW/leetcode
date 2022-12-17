class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> startIndex;
        vector<int> endIndex;
        char start = needle[0];
        char end = needle[needle.length() - 1];
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == start) {
                startIndex.push_back(i);
            }
            if (haystack[i] == end) {
                int startI = i - needle.length() + 1;
                if (!binary_search(startIndex.begin(), startIndex.end(), startI)) continue;
                if (!checkStr(startI, i, haystack, needle)) continue;
                return startI;
            }
        }
        return -1;
    }

    bool checkStr(int start, int end, string& haystack, string& needle) {
        for (int i = 0; i <= end - start; i ++) {
            if (haystack[start + i] != needle[i]) return false;
        }
        return true;
    }
};
