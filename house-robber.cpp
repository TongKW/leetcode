class Solution {
public:
    int included_dp[100];
    int excluded_dp[100];
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        included_dp[0] = nums[0];
        excluded_dp[0] = 0;
        included_dp[1] = nums[1];
        excluded_dp[1] = nums[0];
        for (int i = 2; i < n; i++) {
            included_dp[i] = max(included_dp[i-2], excluded_dp[i-1]) + nums[i];
            excluded_dp[i] = max(included_dp[i-1], excluded_dp[i-1]);
        }
        return max(included_dp[n-1], excluded_dp[n-1]);
    }
};
