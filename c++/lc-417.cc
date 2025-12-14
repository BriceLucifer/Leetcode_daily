#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        auto rows = heights.size();
        auto cols = heights[0].size();
        auto pacific = vector<vector<bool>>(rows, vector<bool>(cols, false));
        auto atlanic = vector<vector<bool>>(rows, vector<bool>(cols, false));
        auto dx = vector<int>{1, -1, 0, 0};
        auto dy = vector<int>{0, 0, 1, -1};

        function<void(int,int, vector<vector<bool>>&)> dfs = [&](int i, int j, vector<vector<bool>>& visited) {
            visited[i][j] = true;
            for (int x = 0; x < 4; x++){
                auto nx = i + dx[x];
                auto ny = j + dy[x];
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
                if (visited[nx][ny]) continue;
                if (heights[nx][ny] >= heights[i][j]) dfs(nx, ny, visited);
            }
        };

        // 从边界搜索
        for(int i = 0; i < rows; i++){
            dfs(i, 0, pacific);
            dfs(i, cols-1, atlanic);
        }

        for(int j = 0; j < cols; j++){
            dfs(0, j, pacific);
            dfs(rows-1, j, atlanic);
        }

        vector<vector<int>> result;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (pacific[i][j] && atlanic[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }
};

int main(){
    cout << "";
    return 0;
}
