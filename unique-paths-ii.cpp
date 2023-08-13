class Solution {
public:
    int m;
    int n;
    int countMap[100][100] = {0};

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid[0].size();
        n = obstacleGrid.size();

        countMap[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    countMap[i][j] = 0;
                    continue;
                }
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
