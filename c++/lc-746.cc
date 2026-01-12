#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int len = cost.size();

        vector<int> dp(len+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i <= len; i++){
            if (i < len)
                dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            else
                dp[i] = min(dp[i-1], dp[i-2]);
        }

        return dp.back();
    }
};

int main() {
    vector<int> cost {10,15,20};
    Solution s{};
    cout << s.minCostClimbingStairs(cost) << endl;
}
