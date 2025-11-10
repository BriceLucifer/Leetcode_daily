#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // the stairs we climb
        auto stairs {cost.size()};

        // you can start at 0 1
        // make the min cost of climbing stairs
        vector<int> dp(stairs);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < stairs; ++i) {
            // 注意状态转移 其实就是在爬楼梯基础上 + 一个计算最小cost
            dp[i] = cost[i] + min<int>(dp[i-1], dp[i-2]);
        }

        return min<int>(dp[stairs-1], dp[stairs-2]);
    }
};

int main() {
    vector<int> cost {10,15,20};
    Solution s{};
    cout << s.minCostClimbingStairs(cost) << endl;
}
