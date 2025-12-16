#include <functional>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        constexpr long long NEG = -(1LL<<50);
        vector<vector<int>> children(n + 1);
        vector<vector<long long>> dp0, dp1;

        for (auto &e : hierarchy) {
            int u = e[0], v = e[1]; // u 是上司，v 是下属
            children[u].push_back(v);
        }

        function<long long(int)> dfs = [&](int u) -> long long {
            long long res = max(0LL, (long long)future[u - 1] - present[u - 1]);
            for (int v : children[u]) {
                res += dfs(v);
            }
            return res;
        };

        // I need 2 dp
        // one for supervisor didn't buy
        // one for supervisor did buy

        return (int)dfs(1);
    }
};



int main(){

    cout << '\n';
    return 0;
}
