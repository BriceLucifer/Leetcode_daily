#include <algorithm>
#include <climits>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // from source to target
        // useing original with the same index to find the way to changes with the same index
        // the cost of the same index
        // question is to find the lowest cost make source to target
        const int length = source.size();
        long long INF = LONG_MAX / 2;
        // 26 个英文字母
        vector<vector<long long>> dist (26, vector<long long>(26, INF));
        // a -> a : cost = 0
        // b -> b : cost = 0
        // same ..
        for(int i = 0; i < 26; i++){
            dist[i][i] = 0;
        }

        for(int i = 0; i < original.size(); i++){
            auto u = original[i] - 'a';
            auto v = changed[i] - 'a';
            long long w = cost[i];
            dist[u][v] = min(dist[u][v], w);
        }

        for (int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++){
                if (dist[i][k] == INF){
                    continue;
                }

                for(int j = 0; j < 26; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        auto ans = 0LL;
        for(int i = 0; i < length; i++){
            if (source[i] == target[i]) {
                continue;
            } else {
                auto u = source[i] - 'a';
                auto v = target[i] - 'a';

                long long cur_cost = dist[u][v];
                if (cur_cost == INF){
                    return -1;
                } else {
                    ans += cur_cost;
                }
            }
        }

        return ans;
    }
};
