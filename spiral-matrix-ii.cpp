class Solution {
public:
    int x = 0;
    int y = -1;
    int steps = 0;
    int current = 1;
    int final = 0;
    int ori = 0;

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int> (n, 0));
        steps = n * 2;
        final = n * n;
        
        while (current <= final) {
            for (int i = 0; i < steps / 2; i++) {
                step(result);
            }
            steps -= 1;
            ori = (ori + 1) % 4;
        }
        return result;
    }

    void step(vector<vector<int>>& result) {
        if (ori == 0) {
            y += 1;
        } else if (ori == 1) {
            x += 1;
        } else if (ori == 2) {
            y -= 1;
        } else if (ori == 3) {
            x -= 1;
        }
        result[x][y] = current;
        current += 1;
    }
};
