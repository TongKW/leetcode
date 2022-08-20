#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](const vector<int>& vec1, const vector<int>& vec2) {
                if (vec1[0] == vec2[0]) return vec1[1] < vec2[1];
                return vec1[0] < vec2[0];
            });
            int begin, end;
            vector<vector<int>> ans;
            if (intervals.size()) {
                begin = intervals[0][0];
                end = intervals[0][1];
                for (int i = 1; i < intervals.size(); i++) {
                    if (intervals[i][0] <= end) {
                        end = max(intervals[i][1], end);
                        continue;
                    }
                    ans.push_back({begin, end});
                    begin = intervals[i][0];
                    end = intervals[i][1];
                }
                ans.push_back({begin, end});
            }
            return ans;
        }
};
