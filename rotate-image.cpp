#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int s = matrix.size();
        int left = 0; 
        int right = matrix.size() - 2;
        int x = 0;
        while (right - left >= s % 2) {
            for (int y = left; y <= right; y++) {
                roateFourCorner(matrix, x, y);
            }
            left++; right--; x++;
        }
    }
private:
    void roateFourCorner(vector<vector<int>>& matrix, int x, int y) {
        int temp = matrix[x][y];
        int s = matrix.size() - 1;
        matrix[x][y] = matrix[s-y][x];
        matrix[s-y][x] = matrix[s-x][s-y];
        matrix[s-x][s-y] = matrix[y][s-x];
        matrix[y][s-x] = temp;
    }
};
