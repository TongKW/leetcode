class Solution {
public:
    map<int, int> num_earn;
    vector<vector<int>> isolated_nums;
    int deleteAndEarn(vector<int>& nums) {
        for (int num : nums) {
            if (num_earn.find(num) == num_earn.end()) {
                num_earn[num] = num;
            } else {
                num_earn[num] += num;
            }
        }
        int temp = num_earn.begin()->first;
        int start = temp;
        int end = temp - 1;
        
        for (map<int, int>::iterator i = num_earn.begin(); i != num_earn.end(); i++) {
            int num = i->first;
            if (num == end + 1) {
                end = num;
            } else {
                isolated_nums.push_back({start, end});
                start = num;
                end = num;
            }
        }
        isolated_nums.push_back({start, end});

        int ans = 0;
        for (vector<int> pair : isolated_nums) {
            ans += max_in_iso(pair[0], pair[1]);
        }
        return ans;
    }

    int max_in_iso(int start, int end) {
        cout << start << ", " << end << endl;
        int n = end - start + 1;
        if (n == 1) return num_earn[start];
        int included_dp[n];
        int excluded_dp[n];
        included_dp[0] = num_earn[start];
        excluded_dp[0] = 0;
        included_dp[1] = num_earn[start + 1];
        excluded_dp[1] = num_earn[start];
        for (int i = 2; i < n; i++) {
            included_dp[i] = max(included_dp[i-2], excluded_dp[i-1]) + num_earn[start+i];
            excluded_dp[i] = max(included_dp[i-1], excluded_dp[i-1]);
        }
        return max(included_dp[n-1], excluded_dp[n-1]);
    }
};
