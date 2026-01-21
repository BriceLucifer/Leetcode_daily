#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int length = nums.size();
        vector<int> pre_max(length, nums.front());
        // 0..i max_value
        // [nums[0], max(prefix[i - 1], nums[i])]
        vector<int> suff_max(length, nums.back());
        // i..length - 1 max_value
        // [..., max(nums[i], suff[i + 1]),nums[length - 1]]

        for(int i = 1; i < length; i++){
            pre_max[i] = max(pre_max[i-1], nums[i]);
        }

        for(int i = length - 2; i >= 0; i--){
            suff_max[i] = max(suff_max[i+1], nums[i]);
        }

        long long result {0} ;
        for(int j = 1; j < length - 1; j++){
            result = max((1LL * pre_max[j - 1] - 1LL * nums[j]) * (1LL * suff_max[j+1]), result);
        }

        return result > 0 ? result : 0;

    }
};
