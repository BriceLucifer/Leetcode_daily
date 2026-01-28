#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // setting the staring point
        auto start = k - 1;

        // set up your own graph
        vector<vector<pair<int, int>>> graph(n);

        for(auto &e: times){
            auto u {e[0] - 1}, v {e[1] - 1}, w {e[2]};
            graph[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (visited[u]) continue;

            visited[u] = true;

            for(auto &[v, w]: graph[u]){
                if (dist[u] + w < dist[v] && visited[v] != true){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if (visited[i] == false && dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
