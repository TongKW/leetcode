#include <iostream>
#include <vector>
using namespace std;

// Kadane’s Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_val = INT_MIN;
        int local_max;
        max_val = nums[0];
        local_max = max_val;
        for (int i = 1; i < nums.size(); i++) {
            local_max = max(local_max + nums[i], nums[i]);
            if (local_max > max_val) max_val = local_max;
        }
        return max_val;
    }
};
