#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        auto rows = grid.size();
        auto cols = grid[0].size();
        auto length = 0;
        auto ocean = 0;
        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == 1){
                    q.push({i, j});
                }
                if (grid[i][j] == 0){
                    ocean++;
                }
            }
        }

        if (q.size() == rows * cols || ocean == rows * cols){
            return -1;
        }

        auto step = 0;
        while (!q.empty()) {
            auto has_space = false;
            auto size = q.size();
            for(int i = 0; i < size; i++){
                auto [x,y] = q.front(); q.pop();
                // 四个方向
                for(auto &[dx, dy]: directions){
                    auto nx = x + dx;
                    auto ny = y + dy;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0){
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                        has_space = true;
                    }
                }
            }
            if (has_space) {
                step++;
            }
        }
        return step;
    }
};

int main(){
    vector<vector<int>> grid {{1,0,1},{0,0,0},{1,0,1}};
    auto s {Solution()};
    auto result = s.maxDistance(grid);
    cout << result << '\n';
    return 0;
}
