#include <vector>

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // 1️⃣ 构造二维前缀和
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i-1][j-1]
                          + pre[i-1][j]
                          + pre[i][j-1]
                          - pre[i-1][j-1];
            }
        }

        int ans = 0;

        // 2️⃣ 枚举边长
        for (int len = 1; len <= min(m, n); len++) {
            bool ok = false;
            // 3️⃣ 枚举左上角
            for (int i = 0; i + len <= m; i++) {
                for (int j = 0; j + len <= n; j++) {
                    int sum = pre[i+len][j+len]
                            - pre[i][j+len]
                            - pre[i+len][j]
                            + pre[i][j];
                    if (sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) ans = len;
            else break;  // ⚡ 单调性剪枝
        }

        return ans;
    }
};
