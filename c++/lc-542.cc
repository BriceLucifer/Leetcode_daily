#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        auto rows = mat.size();
        auto cols = mat[0].size();
        auto result = vector<vector<int>>(rows, vector<int>(cols, -1));
        auto q = queue<pair<int, int>>{};
        auto dx = vector<int>{1, -1, 0, 0};
        auto dy = vector<int>{0, 0, 1, -1};

        for(int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (mat[i][j] == 0){
                    q.push({i, j});
                    // mark the result as long as the item self is zero, we set to zero
                    result[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            // check size
            auto size = q.size();
            // set up the step to go through
            for(int z = 0; z < size; z++){
                auto [x, y] = q.front(); q.pop();
                // four direction
                for(int k = 0; k < 4; k++){
                    auto nx = dx[k] + x;
                    auto ny = dy[k] + y;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && result[nx][ny] == -1){
                        result[nx][ny] = result[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return result;
    }
};


int main(){
    cout << "\n";
    return 0;
}
