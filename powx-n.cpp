class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (x == -1 && n % 2) return -1;
        if (x == -1 && !(n % 2)) return 1;
        if (n == INT_MIN && x > 1) return 0;
        if (n == INT_MAX && x < 1) return 0;
        if (n < 0) {
            if (n == -1) return 1 / x;
            return 1 / myPow(x, -n);
        }
        if (n == 1) return x;
        double ans = 1;
        while (n > 0) {
            ans *= x;
            n -= 1;
            if (ans == 0) return 0;
        }
        return ans;
    }
};
