#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1000000007LL;

        vector<long long> ys, xs;
        ys.push_back(1);
        ys.push_back(m);
        for (int y : hFences) ys.push_back(y);

        xs.push_back(1);
        xs.push_back(n);
        for (int x : vFences) xs.push_back(x);

        sort(ys.begin(), ys.end());
        sort(xs.begin(), xs.end());

        unordered_set<long long> heightSet;
        int Y = (int)ys.size();
        for (int i = 0; i < Y; i++) {
            for (int j = i + 1; j < Y; j++) {
                heightSet.insert(ys[j] - ys[i]);
            }
        }

        long long best = -1;
        int X = (int)xs.size();
        for (int i = 0; i < X; i++) {
            for (int j = i + 1; j < X; j++) {
                long long w = xs[j] - xs[i];
                if (heightSet.count(w)) best = max(best, w);
            }
        }

        if (best == -1) return -1;
        return (best % MOD) * (best % MOD) % MOD;
    }
};
