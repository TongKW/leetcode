class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int map[44100] = {0};
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int index = (n + 1) * i + j;
                int index1 = (n + 1) * (i + 1) + j;
                int index2 = (n + 1) * i + (j + 1);     
                if (i == m - 1 || j == n - 1) {
                    map[index] = grid[i][j] + max(map[index1], map[index2]);
                } else {
                    map[index] = grid[i][j] + min(map[index1], map[index2]);
                }
            }
        }
        return map[0];
    }
};
