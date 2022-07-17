#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (lookup.count(target - nums[i]) != 0) {
                ans = {i, lookup[target - nums[i]]};
            }
            lookup[nums[i]] = i;
        }
        return ans;
    }
private:
    unordered_map<int, int> lookup;
    vector<int> ans;
};