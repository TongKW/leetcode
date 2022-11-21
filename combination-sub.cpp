#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Solution 1.0: Recursion
class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // sort candidates vector
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, 0, candidates.size() - 1, temp, target);
        return ans;
    }
    void solve(vector<int> &candidates, int s, int e, vector<int> currentComb, int target)
    {
        if (target == 0)
        {
            ans.push_back(currentComb);
            return;
        }
        if (target < candidates[s])
            return;
        for (int i = e; i <= s; i--)
        {
            vector<int> temp = currentComb;
            temp.push_back(candidates[i]);
            solve(candidates, i, e, temp, target - candidates[i]);
        }
    }
};

// Solution 2: Improved version of Solution 1.
// Avoid copying vector at vector<int> temp = currentComb; by push and pop instead
class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // sort candidates vector
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, 0, candidates.size() - 1, temp, target);
        return ans;
    }
    void solve(vector<int> &candidates, int s, int e, vector<int> &currentComb, int target)
    {
        if (target == 0)
        {
            ans.push_back(currentComb);
            return;
        }
        if (target < candidates[s])
            return;
        for (int i = s; i <= e; i++)
        {
            currentComb.push_back(candidates[i]);
            solve(candidates, i, e, currentComb, target - candidates[i]);
            currentComb.pop_back();
        }
    }
};
