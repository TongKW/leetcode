struct Position {
    int row;
    int col;
    bool top;
    bool ori; // orientation
    Position(int r, int c, bool t, bool o) : row(r), col(c), top(t), ori(o) {}
};

class Solution {
public:
    vector<int> ans;
    int max_row;
    int max_col;
    vector<int> findBall(vector<vector<int>>& grid) {
        max_row = grid.size() - 1;
        max_col = grid[0].size() - 1;
        for (int i = 0; i <= max_col; i++) {
            Position current_pos = Position(0, i, true, grid[0][i] == 1);
            while (current_pos.row <= max_row) {
                if (checkStuck(current_pos, grid)) {
                    ans.push_back(-1);
                    break;
                }
                step(current_pos, grid);
            }
            if (current_pos.row > max_row) {
                ans.push_back(current_pos.col);
            }
        }
        return ans;
    }

    void step(Position& pos, vector<vector<int>>& grid) {
        if (!pos.top) {
            pos.row += 1;
            pos.top = true;
            if (pos.row <= max_row) {
                pos.ori = grid[pos.row][pos.col] == 1;
            }
            return;
        }
        if (pos.ori) {
            pos.col += 1;
            pos.top = false;
        } else {
            pos.col -= 1;
            pos.top = false;
        }
    }

    bool checkStuck(Position& pos, vector<vector<int>>& grid) {
        if (!pos.top) return false;
        if (pos.ori) {
            if (pos.col == max_col) return true;
            if (grid[pos.row][pos.col + 1] == -1) return true;
            return false;
        }
        if (pos.col == 0) return true;
        if (grid[pos.row][pos.col - 1] == 1) return true;
        return false;
    }
};
