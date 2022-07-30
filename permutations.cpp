#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;

// Approach 1: recursion
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return solve(nums);
    }
private:
    vector<vector<int>> solve(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 1) {
            ans.push_back(nums);
            return ans;
        }
        // size >= 2
        for (int i = 0; i < nums.size(); i++) {
            vector<int> subs = pop_vec(nums, i);
            vector<vector<int>> subs_p = solve(subs);
            for (int j = 0; j < subs_p.size(); j++) {
                ans.push_back(join_int(subs_p[j], nums[i]));
            }
        }
        return ans;
    }
    // concat vec and int
    vector<int> join_int(vector<int>& vec, int i) {
        vec.push_back(i);
        return vec;
    }
    // pop a specific position from vector
    vector<int> pop_vec(vector<int>& vec, int position) {
        vector<int> temp;
        for (int i = 0; i < vec.size(); i++) {
            if (position == i) continue;
            temp.push_back(vec[i]);
        }
        return temp;
    }
};

// Approach 2: dp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (!init) {
            get_permute_stacks();
        }
        return get_ans(nums);
    }
private:
    unordered_map<int, vector<vector<int>>> permute_stacks;
    bool init = false;
    void get_permute_stacks() {
        permute_stacks[0] = {{0}};
        for (int i = 1; i < 6; i++) {
            permute_stacks[i] = {};
            for (vector<int>& v : permute_stacks[i - 1]) {
                for (int j = 0; j <= i; j ++) {
                    permute_stacks[i].push_back(insert_int_to_vec(v, i, j));
                }
            }
        }
        // set init flag to true
        init = true;
    }
    
    vector<vector<int>> get_ans(vector<int>& nums) {
        vector<vector<int>> ans;
        for (vector<int>& v : permute_stacks[nums.size() - 1]) {
            vector<int> temp {};
            for (int i : v) {
                temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }

    vector<int> insert_int_to_vec(vector<int>& v, int i, int pos) {
        vector<int> temp;
        if (pos == v.size()) {
            for (int elem : v) temp.push_back(elem);
            temp.push_back(i);
            return temp;
        }
        int count = 0;
        for (int elem : v) {
            if (count == pos) temp.push_back(i);
            temp.push_back(elem);
            count ++;
        }
        return temp;
    }
};
