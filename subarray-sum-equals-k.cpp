#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std; 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            if (seq_sums.count(current_sum - k)) {
                total += seq_sums[current_sum - k];
            }
            if (current_sum == k) {
                total += 1;
            }
            if (seq_sums.count(current_sum)) {
                seq_sums[current_sum] += 1;
            } else {
                seq_sums[current_sum] = 1;
            }
        }
        return total;
    }
    
private:
    unordered_map<int, int> seq_sums;
    int total = 0;
};
