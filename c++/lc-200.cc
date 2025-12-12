#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        auto island = 0;
        auto row = grid.size();
        auto col = grid[0].size();
        auto count = 0;

        function<void(int, int)> dfs = [&](int i,int j) -> void {
            if (i < 0 || i >= row || j < 0 || j >= col|| grid[i][j] == '0') return;
            if (grid[i][j] == '1'){
                grid[i][j] = '0';
                dfs(i+1, j);
                dfs(i-1, j);
                dfs(i, j+1);
                dfs(i, j-1);
            }
        };

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if (grid[i][j] == '1'){
                    island +=1;
                    dfs(i, j);
                }
            }
        }

        return island;
    }
};

int main(){
    auto grid = vector<vector<char>> {
          {'1','1','1','1','0'},
          {'1','1','0','1','0'},
          {'1','1','0','0','0'},
          {'0','0','0','0','0'}
    };
    auto s = Solution();
    auto result = s.numIslands(grid);

    cout << result << '\n';
    return 0;
}
