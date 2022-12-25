class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int max1 = rob_help(0, n - 2, nums);
        int max2 = rob_help(1, n - 1, nums);
        return max(max1, max2);
    }

    int rob_help(int s, int e, vector<int>& nums) {
        int included_dp[100];
        int excluded_dp[100];
        int n = e - s + 1;
        if (n == 1) return nums[s];
        included_dp[0] = nums[s];
        excluded_dp[0] = 0;
        included_dp[1] = nums[s+1];
        excluded_dp[1] = nums[s];
        for (int i = 2; i < n; i++) {
            included_dp[i] = max(included_dp[i-2], excluded_dp[i-1]) + nums[s+i];
            excluded_dp[i] = max(included_dp[i-1], excluded_dp[i-1]);
        }
        return max(included_dp[n-1], excluded_dp[n-1]);
    } 
};
