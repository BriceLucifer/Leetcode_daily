#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result {0};
        int length = nums.size();
        for(int i {0}, j {length - 1}; i < j; i++, j--){
            result = max(nums[i] + nums[j], result);
        }

        return result;
    }
};
