class Solution {
public:
    int x_max;
    int y_max;
    int visited[10][10];
    vector<int> ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        x_max = n - 1;
        y_max = m - 1;
        int mode = 0;
        int x = 0;
        int y = 0;
        visited[y][x] = 1;
        ans.push_back(matrix[y][x]);
        int total = 1;

        cout << m * n << endl;

        while (total < m * n) {
            if (checkOutOfBound(x, y, mode)) {
                mode += 1;
            }
            step(x, y, mode);
            ans.push_back(matrix[y][x]);
            total += 1;
        }
        return ans;
    }
    void step(int& x, int& y, int mode) {
        if (mode % 4 == 0) {
            x += 1;
            visited[y][x] = 1;
            return;
        }
        if (mode % 4 == 1) {
            y += 1;
            visited[y][x] = 1;
            return;
        }
        if (mode % 4 == 2) {
            x -= 1;
            visited[y][x] = 1;
            return;
        }
        if (mode % 4 == 3) {
            y -= 1;
            visited[y][x] = 1;
            return;
        }
    }

    bool checkOutOfBound(int x, int y, int mode) {
        if (mode % 4 == 0) {
            x += 1;
        }
        else if (mode % 4 == 1) {
            y += 1;
        }
        else if (mode % 4 == 2) {
            x -= 1;
        }
        else {
            y -= 1;
        }
        if (x < 0 || x > x_max || y < 0 || y > y_max) return true;
        return visited[y][x] == 1;
    }
};
