class Solution {
public:
    string generateTheString(int n) {
        return string((n / 2 + n % 2) * 2 - 1, 'a') + string(1 - n % 2, 'b');
    }
};
