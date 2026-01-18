#include <vector>

using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // 前缀和
        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> anti(m + 1, vector<int>(n + 2, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti[i + 1][j] = anti[i][j + 1] + grid[i][j];
            }
        }

        auto check = [&](int r, int c, int k) {
            int target = row[r][c + k] - row[r][c];

            // 行
            for (int i = 0; i < k; ++i) {
                if (row[r + i][c + k] - row[r + i][c] != target)
                    return false;
            }

            // 列
            for (int j = 0; j < k; ++j) {
                if (col[r + k][c + j] - col[r][c + j] != target)
                    return false;
            }

            // 对角线
            int d1 = diag[r + k][c + k] - diag[r][c];
            int d2 = anti[r + k][c] - anti[r][c + k];

            return d1 == target && d2 == target;
        };

        for (int k = min(m, n); k >= 2; --k) {
            for (int i = 0; i + k <= m; ++i) {
                for (int j = 0; j + k <= n; ++j) {
                    if (check(i, j, k))
                        return k;
                }
            }
        }

        return 1;
    }
};
