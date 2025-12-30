#include <vector>

using namespace std;

class Solution {
public:
bool check(vector<vector<int>>& g, int x, int y) {
    if (g[x][y] != 5) return false;

    bool seen[10] = {false};

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int v = g[x + i][y + j];
            if (v < 1 || v > 9 || seen[v]) return false;
            seen[v] = true;
        }
    }

    // try add is the best
    if (g[x-1][y-1] + g[x-1][y] + g[x-1][y+1] != 15) return false;
    if (g[x][y-1]   + g[x][y]   + g[x][y+1]   != 15) return false;
    if (g[x+1][y-1] + g[x+1][y] + g[x+1][y+1] != 15) return false;

    if (g[x-1][y-1] + g[x][y-1] + g[x+1][y-1] != 15) return false;
    if (g[x-1][y]   + g[x][y]   + g[x+1][y]   != 15) return false;
    if (g[x-1][y+1] + g[x][y+1] + g[x+1][y+1] != 15) return false;

    return true;
}

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        auto rows = grid.size();
        auto cols = grid[0].size();

        auto result {0};

        // check as middle element as start which is 1,1
        for (int r = 1; r < rows - 1; r++){
            //                              |- the end of iteration
            // watch out for rows -1 [1, 2, 3, 4]
            // same in cols
            for (int c = 1; c < cols - 1; c++){
                if (check(grid, r, c)){
                    result += 1;
                }
            }
        }

        return result;
    }
};
