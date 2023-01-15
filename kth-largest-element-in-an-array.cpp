class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    int findKthLargest(vector<int>& nums, int k) {
        size = 0;
        for (int num : nums) {
            pq.push(num);
            size++;
            if (size > k) {
                pq.pop();
                size--;
            }
        }
        return pq.top();
    }
};
