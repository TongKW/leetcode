class Solution {
public:
    int countMap[100][100] = {0};

    int m;
    int n;

    int uniquePaths(int a, int b) {
        m = a;
        n = b;

        countMap[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                countMap[i][j] += subPathCount(i-1, j) + subPathCount(i, j-1);
            }
        }
        
        return countMap[n - 1][m - 1];
    }

    int subPathCount(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        return countMap[i][j];
    }
};
