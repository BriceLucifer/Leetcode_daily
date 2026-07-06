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
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // front and end
        // 1..n-1
        auto dp1 = vector<array<int, 2>>(nums.size() - 1, {0, 0});
        // 2..n
        auto dp2 = vector<array<int, 2>>(nums.size() - 1, {0, 0});

        // one state is I not choose dp[i][0] = max(dp[i-1][0], dp[i-1][1])
        // last step no matter if I choose, i didn't choose this time for dp[i][0]
        // one state is that I chose dp[i][1] = dp[i-1][0] + nums[i];

        // House[1]-House[n-1] or House[2]-House[n],

        for(int i = 0; i < nums.size() - 1; i++){
            if (i == 0){
                dp1[i][1] = nums[i];
                dp1[i][0] = 0;
            } else {
                dp1[i][0] = max(dp1[i-1][0], dp1[i-1][1]);
                dp1[i][1] = dp1[i-1][0] + nums[i];
            }
        }

        for(int i = 1; i < nums.size(); i++){
            if (i == 1){
                dp2[i-1][1] = nums[i];
                dp2[i-1][0] = 0;
            } else {
                dp2[i-1][0] = max(dp2[i-2][0], dp2[i-2][1]);
                dp2[i-1][1] = dp2[i-2][0] + nums[i];
            }
        }

        auto dp1_result = max(dp1.back()[0], dp1.back()[1]);
        auto dp2_result = max(dp2.back()[0], dp2.back()[1]);
        return max(dp1_result, dp2_result);
    }
};
