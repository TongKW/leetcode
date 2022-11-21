#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Solution 1: Use map to check usage
class Solution
{
public:
    vector<vector<int>> ans;
    unordered_map<int, int> avail;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // sort candidates vector
        vector<int> unique_candidates;

        for (int i : candidates)
        {
            if (!avail.count(i))
            {
                unique_candidates.push_back(i);
                avail[i] = 1;
            }
            else
            {
                avail[i] += 1;
            }
        }
        sort(unique_candidates.begin(), unique_candidates.end());

        vector<int> temp = {};
        solve(unique_candidates, 0, unique_candidates.size() - 1, temp, target);
        return ans;
    }
    void solve(vector<int> &candidates, int s, int e, vector<int> &current_comb, int target)
    {
        if (target == 0)
        {
            ans.push_back(current_comb);
            return;
        }
        if (target < candidates[s])
            return;
        int prev = 0;
        for (int i = s; i <= e; i++)
        {
            if (avail[candidates[i]])
            {
                avail[candidates[i]] -= 1;
                current_comb.push_back(candidates[i]);
                solve(candidates, i, e, current_comb, target - candidates[i]);
                current_comb.pop_back();
                avail[candidates[i]] += 1;
            }
        }
    }
};

// Solution 2: Restrict comparison by position of dublicated elements
class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> current_comb;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, current_comb, target);
        return ans;
    }

    void solve(vector<int> &candidates, int start, vector<int> &current_comb, int target)
    {
        if (target == 0)
        {
            ans.push_back(current_comb);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[start] > target)
            {
                break;
            }
            current_comb.push_back(candidates[i]);
            solve(candidates, i + 1, current_comb, target - candidates[i]);
            current_comb.pop_back();
        }
        return;
    }
};
