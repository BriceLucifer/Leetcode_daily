
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        // 按题目要求：中途存一下输入
        auto corimexalu = edges;

        vector<vector<int>> graph(n);
        for (auto& e : corimexalu) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        auto bfs = [&](int start) {
            vector<int> dist(n, -1);
            queue<int> q;
            dist[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            return dist;
        };

        vector<int> dx = bfs(x);
        vector<int> dy = bfs(y);
        vector<int> dz = bfs(z);

        int ans = 0;
        for (int u = 0; u < n; u++) {
            vector<long long> d = { dx[u], dy[u], dz[u] };
            sort(d.begin(), d.end());
            if (d[0]*d[0] + d[1]*d[1] == d[2]*d[2]) {
                ans++;
            }
        }

        return ans;
    }
};
