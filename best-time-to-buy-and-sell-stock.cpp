#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int max_earn = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
                continue;
            }
            max_earn = max(prices[i] - lowest, max_earn);
        }
        return max_earn;
    }
};
