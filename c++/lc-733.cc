#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> result {image};
        const int rows = image.size();
        const int cols = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        result[sr][sc] = color;
        vector<pair<int, int>> index {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto target = image[sr][sc];

        while (!q.empty()) {
            const int size = q.size();
            for(int i = 0; i < size; i++){
                auto [x, y] = q.front(); q.pop();
                for(auto &[i_x, i_y]: index){
                    auto cx = x + i_x;
                    auto cy = y + i_y;
                    if (cx >= 0 && cx < rows && cy >= 0 && cy < cols){
                        if (image[cx][cy] == target && result[cx][cy] != color) {
                            q.push({cx, cy});
                            result[cx][cy] = color;
                        }
                    }
                }
            }
        }

        return result;

    }
};
