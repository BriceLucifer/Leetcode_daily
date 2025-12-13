#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        auto rows = grid.size();
        auto cols = grid[0].size();
        auto minutes = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        queue<pair<int, int>> q;
        auto fresh = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                }
                if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while (!q.empty()) {
            auto size = q.size();
            bool rotted = false;

            for(int i = 0; i < size; i++){
                auto [x, y] = q.front(); q.pop();
                for(int k = 0; k < 4; k++){
                    auto nx = x + dx[k];
                    auto ny = y + dy[k];
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if (rotted) minutes++;
        }

        if (fresh > 0) return -1;

        return minutes;
    }
};

int main(){
    // vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    // vector<vector<int>> grid = {{0,2}};
    vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
    auto s = Solution();
    auto result = s.orangesRotting(grid);

    cout << result << '\n';
    return 0;
}
