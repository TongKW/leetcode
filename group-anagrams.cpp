#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (string s : strs) {
            string s_copy = s;
            sort(s_copy.begin(), s_copy.end());
            if (group_map.count(s_copy)) {
                group_map[s_copy].push_back(s);
            } else {
                group_map[s_copy] = {s};
            }
        }
        // After storing all string
        vector<vector<string>> ans;
        for ( const auto &pair : group_map ) {
            ans.push_back(pair.second);
        }
        return ans;
    }
private:
    map<string, vector<string>> group_map;
};
