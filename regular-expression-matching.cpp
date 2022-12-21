class Solution {
public:
    int final_check_dp[30][30];

    bool isMatch(string s, string p) {
        int q = s.size() - p.size() + count(p.begin(), p.end(), '*') * 2;
        if (q < 0) {
            return false;
        }
        return checkMatch(s, p, 0, 0, q);
    }

    bool checkMatch(string& s, string& p, int s_pos, int p_pos, int q) {
        if (q == 0) return finalCheck(s, p, s_pos, p_pos);
        if (final_check_dp[s_pos][p_pos] == 1) return true;
        if (final_check_dp[s_pos][p_pos] == -1) return false;

        bool ans = false;

        if (s_pos == s.size() || p_pos == p.size()) {
            if (!q && s.size() - s_pos == p.size() - p_pos) {
                ans = true;
            }
            final_check_dp[s_pos][p_pos] = ans ? 1 : -1;
            return ans;
        }
        if (p[p_pos+1] == '*') {
            if (s[s_pos] == p[p_pos] || p[p_pos] == '.') {
                ans = (checkMatch(s, p, s_pos + 1, p_pos, q - 1) || checkMatch(s, p, s_pos, p_pos + 2, q));
            } else {
                ans = checkMatch(s, p, s_pos, p_pos + 2, q);
            }
        } else {
            if (s[s_pos] == p[p_pos] || p[p_pos] == '.') {
                ans = checkMatch(s, p, s_pos + 1, p_pos + 1, q);
            }
        }
        final_check_dp[s_pos][p_pos] = ans ? 1 : -1;
        return ans;
    }

    bool finalCheck(string& s, string& p, int s_pos, int p_pos) {
        string ss = s.substr(s_pos); // s substring
        string ps = p.substr(p_pos); // p substring

        vector<int> star_pos;
        for (int i = ps.size() - 1; i >= 0; i--) {
            if (ps[i] == '*') star_pos.push_back(i - 1);
        }
        for (int pos : star_pos) {
            ps.erase(pos, 2);
        }
        if (ss.size() != ps.size()) {
            return false;
        }
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i] != ps[i] && ps[i] != '.') {
                return false;
            }
        }
        return true;
    }
};
