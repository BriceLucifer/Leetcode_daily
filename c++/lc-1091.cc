#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // n x n
        auto n = grid.size();
        // grid[i][j] == 0
        // 8 direction:
        auto dx = vector<int>{1, -1, 0, 0, -1, 1, -1, 1};
        auto dy = vector<int>{0, 0, 1, -1, -1, 1, 1, -1};

        // bfs
        queue<pair<int, int>> q;
        auto visited = vector<vector<int>>(n, vector<int>(n, 0));
        auto length = 1;
        if (grid[0][0] != 0 && grid[n-1][n-1] != 0) return -1;

        // 从左上角到右下角 n-1, n-1
        // if (i == n - 1 && j == n - 1 && grid[i][j] == 0)
        visited[0][0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            auto size = q.size();
            for(int i = 0; i < size; i++){
                auto [x, y] = q.front(); q.pop();
                if (x == n - 1 && y == n - 1) return length;
                for (int k = 0; k < 8; k++){
                    auto nx = dx[k] + x;
                    auto ny = dy[k] + y;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && visited[nx][ny] == 0){
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            length += 1;
        }

        return -1;
    }
};


int main(){
    auto grid = vector<vector<int>>{{0,0,0}, {1,1,0}, {1,1,0}};
    auto s = Solution();
    auto result = s.shortestPathBinaryMatrix(grid);
    cout << result << '\n';
    return 0;
}
