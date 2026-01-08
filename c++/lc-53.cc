#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     const int len = nums.size();
    //     if (len == 1){ return nums.front(); }

    //     vector<int> dp = vector<int>(len, 0);
    //     int ans = nums[0];
    //     for(int i = 0; i < len; i++){
    //         // = 0的时候复制
    //         if (i == 0) dp[i] = nums[i];
    //         else {
    //             dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    //             ans = max(ans, dp[i]);
    //         }
    //     }

    //     return ans;
    // }
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums.front();
        int cur_sum = 0;

        for(int& i: nums){
            cur_sum = max(cur_sum, 0);
            cur_sum += i;
            max_sum = max(cur_sum, max_sum);
        }

        return max_sum;
    }
};
