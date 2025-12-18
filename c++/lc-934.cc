#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        auto n = grid.size();
        queue<pair<int, int>> q;
        auto dx = vector<int>{1, -1, 0, 0};
        auto dy = vector<int>{0, 0, 1, -1};

        // [0, 1]
        // [1, 0]
        // find the island
        // mark it to -1
        // -2 -1 代表visited 0 代表周围没有元素
        function<void(int, int)> dfs_mark = [&](int i, int j){
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return;
            grid[i][j] = -1;
            q.push({i, j});
            // 四个方向
            for(int k = 0; k < 4; k++){
                auto nx = i + dx[k];
                auto ny = j + dy[k];
                dfs_mark(nx, ny);
            }
        };

        bool found = false;
        for(int i = 0; i < n && !found; i++){
            for(int j = 0; j < n; j++){
                // find the first island and mark
                if (grid[i][j] == 1) {
                    dfs_mark(i, j);
                    found = true;
                    break;
                }
            }
        }


        auto step = 0;
        while (!q.empty()) {
            auto size = q.size();
            for(int i = 0; i < size; i++){
                auto [x, y] = q.front(); q.pop();
                for(int k = 0; k < 4; k++){
                    auto nx = x + dx[k];
                    auto ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n ){
                       if (grid[nx][ny] == 1) {
                           return step;
                       }
                       if (grid[nx][ny] == 0){
                           grid[nx][ny] = -2;
                           q.push({nx, ny});
                       }
                       // -2 和 -1 忽略
                    }
                }
            }
            step++;
        }

        return step;
    }
};

int main(){
    auto grid = vector<vector<int>>{{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    auto s = Solution();
    auto result = s.shortestBridge(grid);

    cout << result << '\n';
    return 0;
}
