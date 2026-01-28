#include <climits>      // INT_MAX：用于表示“当前不可达/无穷大”
#include <functional>   // greater<>：让 priority_queue 变成小根堆
#include <queue>        // priority_queue
#include <utility>      // pair
#include <vector>       // vector

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        if (n == 2) return edges.front()[2];

        // adj[u] 里存的是：从 u 出发能走到的 (v, cost)
        // 这是“邻接表”表示法：适合稀疏图，遍历某个点的所有出边很快 O(outdegree)
        vector<vector<pair<int, int>>> adj(n);

        // ----------------------------
        // 1) 建图：把题目里的“可反转一次”行为，近似成“额外的一条反向边”
        // ----------------------------
        for (auto &e : edges) {
            auto u = e[0], v = e[1], w = e[2];

            // 原始有向边：u -> v，花费 w
            adj[u].push_back({v, w});

            // 近似加入“反向走”的可能性：v -> u，花费 2*w
            // 直觉：反转边的代价按题意是 2*w，所以我们把它当成一条额外边加入图中。
            // 注意：这一步等价于把“开关限制”忽略掉，只保留“反向移动代价更高”这一点。
            adj[v].push_back({u, 2 * w});
        }

        // ----------------------------
        // 2) distence[x]：从 0 到 x 的“当前已知最小花费”
        // 初始化为 INT_MAX 表示还不知道怎么到达（无穷大）
        // ----------------------------
        vector<int> distence(n, INT_MAX);

        // visit[x]：Dijkstra 里常用的“定型标记”
        // visit[x] = true 表示：x 的最短距离已经确定，不会再被更小值更新
        // 原因：边权非负时，Dijkstra 每次弹出的最小 dist 节点就是最终最短
        vector<bool> visit(n, false);

        // ----------------------------
        // 3) 小根堆（优先队列）
        // pq 里存 (当前距离, 节点)
        // 使用 greater<> 让 priority_queue 变成“距离最小的先出”
        // ----------------------------
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        // 起点 0 到 0 的距离是 0
        distence[0] = 0;

        // 把起点放入堆：表示“接下来从它开始扩展”
        pq.push({0, 0});

        // ----------------------------
        // 4) Dijkstra 主循环
        // 每次从堆里取出“当前全局最便宜”的节点 u，并尝试用它更新邻居的最短距离
        // ----------------------------
        while (!pq.empty()) {

            // 取出当前距离最小的候选 (s, u)
            // s 是从起点到 u 的候选距离（可能是旧版本）
            auto [s, u] = pq.top();
            pq.pop();

            // 如果当前弹出来的点就是终点 n-1，那么 s 就是最短路，可以直接返回
            // 原因：Dijkstra 性质：第一次弹出某个节点时，它的距离就是全局最小且最终确定
            //（前提：所有边权非负）
            if (u == n - 1) {
                return s;
            }

            // 如果 u 已经“定型”（visit[u] == true），说明我们以前已经用更小的距离处理过它
            // 当前这个 (s,u) 就是堆里的旧条目，直接跳过即可
            if (visit[u]) {
                continue;
            }

            // 标记 u 定型：以后不再需要从 u 出发更新（因为不可能出现更短的到 u 的路径了）
            visit[u] = true;

            // ----------------------------
            // 5) 松弛（relax）操作：用 u 去更新所有 u -> v 的边
            // ----------------------------
            for (auto &[v, w] : adj[u]) {

                // 如果 distence[u] 还等于 INT_MAX，表示 u 根本不可达，那么 distence[u] + w 会溢出
                // 这里依赖于 Dijkstra 的性质：只有可达点才会被弹出并 visit，因此一般不会发生
                // 但你可以加一行 if (distence[u] == INT_MAX) continue; 更保险

                // 尝试走 u -> v：
                // 新的候选距离 = distence[u] + w
                // 如果它更小，就更新 distence[v]
                //
                // 这里写 !visit[v] 是一种常见“剪枝”：
                // v 一旦 visit[v]==true，说明 v 的最短路已经确定，再更新也不会成功（非负权下）
                // 所以可以直接跳过，减少堆操作。
                if (distence[u] + w < distence[v] && !visit[v]) {
                    distence[v] = distence[u] + w;

                    // 把新的候选 (distence[v], v) 放入堆
                    // 注意：堆里可能存在 v 的旧版本，之后会被 visit[v] 或 dist 检查过滤掉
                    pq.push({distence[v], v});
                }
            }
        }

        // 堆空了还没到达终点：说明终点不可达
        return -1;
    }
};
