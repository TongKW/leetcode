class Solution {
public:
    bool canJump(vector<int>& nums) {
        nums_len = nums.size();
        if (nums_len == 1) return true;
        for (int i = 0; i < nums.size(); i ++) {
            if (!nums[i]) continue;
            int arrived = insert(i, i + nums[i]);
            if (arrived) return true;
        }
        if (intervalStarts[0] == 0 && intervalEnds[0] >= nums_len - 1) return true;
        return false;
    }

    bool insert(int start, int end) {
        int s_location = find_location(start);
        int e_location = find_location(end);

        if (s_location == e_location && s_location % 2 == 0) {
            int pos = s_location / 2;
            intervalStarts.insert(intervalStarts.begin() + pos, start);
            intervalEnds.insert(intervalEnds.begin() + pos, end);
            return check_finished(start, end);
        }
        int s_pos = s_location / 2;
        int e_pos = e_location / 2;
        merge(s_pos, e_pos);
        int min_val = min(start, intervalStarts[s_pos]);
        int max_val = max(end, intervalEnds[s_pos]);
        intervalStarts[s_pos] = min_val;
        intervalEnds[s_pos] = max_val;
        return check_finished(min_val, max_val);
    }

    bool check_finished(int min_val, int max_val) {
        if (min_val == 0 && max_val >= nums_len) return true;
        return false;
    }

    int find_location(int i) {
        int is_len = intervalStarts.size();
        if (!is_len) return 0;
        if (i < intervalStarts[0]) return 0;
        if (i > intervalEnds[is_len - 1]) return is_len * 2;
        int pos = lower_bound(intervalEnds.begin(), intervalEnds.end(), i) - intervalEnds.begin();
        if (i >= intervalStarts[pos]) {
            return 2 * pos + 1;
        }
        return 2 * pos;
    }

    void merge(int s, int e) {
        if (s + 1 >= intervalStarts.size()) return;
        int upper1 = min((int) intervalStarts.size(), e + 1);
        int upper2 = min((int) intervalStarts.size(), e);

        intervalStarts.erase(intervalStarts.begin() + s + 1, intervalStarts.begin() + upper1);
        intervalEnds.erase(intervalEnds.begin() + s, intervalStarts.begin() + upper2);
    }

private:
    vector<int> intervalStarts;
    vector<int> intervalEnds;
    int nums_len;
};
