#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        solve(0, k, n, comb);
        return ans;
    }
    void solve(int start, int k, int n, vector<int>& comb) {
        if (k == 0 && n == 0) {
            ans.push_back(comb); // Base case
            return;
        };
        if (k == 0 || n <= 0) return; // Checking Case 1
        if (start + k > 9) return; // Checking Case 2
        if ((2 * start + k + 1) * k / 2 > n) return; // Checking Case 3
        for (int i = start + 1; i <= 9; i++) {
            comb.push_back(i);
            solve(i, k-1, n-i, comb); // Recursion
            comb.pop_back();
        }
    }
};
