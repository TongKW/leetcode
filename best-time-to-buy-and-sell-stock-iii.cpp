#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        int lowest = prices[0];
        for (int i = 1; i < n; i++) {
            int profit = prices[i] - lowest;
            dp1[i] = max(dp1[i], max(profit, dp1[i-1]));
            lowest = min(lowest, prices[i]);
        }
        int higest = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            int profit = higest - prices[i];
            dp2[i] = max(dp2[i], max(profit, dp2[i+1]));
            higest = max(higest, prices[i]);
        }
        int max_profit = 0;
        for (int i = 0; i < n; i++) {
            max_profit = max(max_profit, dp1[i] + dp2[i]);
        }
        return max_profit;
    }
};
