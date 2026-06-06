#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
    	// leftsum = [ sum(0..i)]
    	// rightsum = [ sum(i..0)]
    	// result = abs [leftsum[i] - rightsum[i]]

        if (nums.size() == 1) return {0};
        const int length = nums.size();
        vector<int> sum = nums;

        for(int i = 1; i < length; i++){
            sum[i] = sum[i] + sum[i-1];
        }

        // [leftsum..index..rightsum]
        vector<int> left = nums;
        vector<int> right = nums;
        for(int i = 0; i < length; i++){
            right[i] = sum[length - 1] - sum[i];
            left[i] = sum[i] - nums[i];
        }

        vector<int> result = nums;
        for(int i = 0; i < length; i++){
            result[i] = abs(left[i] - right[i]);
        }

        return result;
    }
};
