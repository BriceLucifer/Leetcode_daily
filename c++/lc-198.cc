#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
         * nums = [1,2,3,1]
         Output: 4
         Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
         Total amount you can rob = 1 + 3 = 4.
         */

        auto dp = vector<array<int, 2>>(nums.size(), {0, 0});

        // one state is I not choose dp[i][0] = max(dp[i-1][0], dp[i-1][1])
        // last step no matter if I choose, i didn't choose this time for dp[i][0]
        // one state is that I chose dp[i][1] = dp[i-1][0] + nums[i];

        for(int i = 0; i < nums.size(); i++){
            if (i == 0){
                dp[i][1] = nums[i];
                dp[i][0] = 0;
            } else {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = dp[i-1][0] + nums[i];
            }
        }

        return max(dp.back()[0], dp.back()[1]);
    }
};
