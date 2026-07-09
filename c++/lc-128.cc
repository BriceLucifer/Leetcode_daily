#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> sz;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) {
            return;
        }

        if (sz[rootA] < sz[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            // 重复数字直接跳过
            if (parent.count(x)) {
                continue;
            }

            // 先把 x 建成一个单独集合
            parent[x] = x;
            sz[x] = 1;

            // 如果左边连续数字存在，合并
            if (parent.count(x - 1)) {
                unite(x, x - 1);
            }

            // 如果右边连续数字存在，合并
            if (parent.count(x + 1)) {
                unite(x, x + 1);
            }

            // x 所在集合的大小，就是当前连续段长度
            ans = max(ans, sz[find(x)]);
        }

        return ans;
    }
};
