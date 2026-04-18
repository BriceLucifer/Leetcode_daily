#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums){
        int a = 0, b = 0;

        for (const int &x: nums){
            int new_a = b + x;
            b = max(a, b);
            a = new_a;
        }

        return max(a, b);
    }

    int rob2(vector<int>& nums){
        const int len = nums.size();

        int dp[1024][2];
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        // 0 -> choose
        // 1 -> non-choose
        for (int i = 1; i < len; i++){
            // no choose + choose one
            dp[i][0] = dp[i-1][1] + nums[i];
            // for now nochoose
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }

        return max(dp[len-1][0], dp[len-1][1]);
    }
};
