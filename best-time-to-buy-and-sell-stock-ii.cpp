class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int max_earn = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i-1]) {
                max_earn += prices[i-1] - lowest;
                lowest = prices[i];
                continue;
            }
        }
        max_earn += prices[prices.size() - 1] - lowest;
        return max_earn;
    }
};
