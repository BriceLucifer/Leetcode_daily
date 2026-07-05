#include <algorithm>
#include <vector>

using namespace std;

// kadane algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto result = INT_MIN;
        auto cursum = 0;
        // nums = [-2,1,-3,4,-1,2,1,-5,4]

        for(int i = 0; i < nums.size(); i++){
            cursum = max(nums[i], cursum + nums[i]);
            result = max(result, cursum);
        }

        return result;
    }
};
