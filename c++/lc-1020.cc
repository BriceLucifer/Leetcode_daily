#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        auto rows = grid.size();
        auto cols = grid[0].size();
        auto nums = 0;

        function<int(int, int)> dfs = [&](int i, int j){
            if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) return 0;
            grid[i][j] = 0;
            return 1 + dfs(i+1, j) + dfs(i-1, j) + dfs(i, j+1) + dfs(i, j-1);
        };

        for (int i = 0; i < rows; i++){
            if (i == 0 || i == rows-1){
                for (int j = 0; j < cols; j++){
                    if (grid[i][j] == 1){
                        dfs(i, j);
                    }
                }
            } else {
                if (grid[i][0] == 1){
                    dfs(i, 0);
                }
                if (grid[i][cols-1] == 1){
                    dfs(i, cols-1);
                }
            }
        }


        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == 1){
                    nums += dfs(i, j);
                }
            }
        }

        return nums;
    }
};

int main(){
    vector<vector<int>> grid {
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0},
    };

    auto s = Solution();
    auto result = s.numEnclaves(grid);

    cout << result << '\n';
}
