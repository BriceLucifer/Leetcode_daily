#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        // 从0， 0开始
        // dp 题目
        vector<vector<int>> dp (rows, vector<int>(cols, 0));
        if (rows == 0 || cols == 0) return 0;
        dp[0][0] = grid[0][0];
        for(int i = 1; i < rows; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int j = 1; j < cols; j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp.back().back();
    }
};
