#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = nums.size();
        if (!s) return {-1, -1};
        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lower == s) return {-1, -1};
        if (nums[lower] != target)  return {-1, -1};
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {lower, upper - 1};
    }
};
