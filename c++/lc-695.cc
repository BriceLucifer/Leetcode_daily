#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        auto row = grid.size();
        auto col = grid[0].size();
        auto area = 0;

        function<int(int, int)> dfs_with_return = [&](int i, int j) -> int {
            if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) return 0;
            grid[i][j] = 0;
            return 1 + dfs_with_return(i+1, j) + dfs_with_return(i-1, j) + dfs_with_return(i, j+1) + dfs_with_return(i, j-1);
        };


        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if (grid[i][j] == 1){
                    auto temp = dfs_with_return(i, j);
                    area = max(temp, area);
                }
            }
        }

        return area;
    }
};
