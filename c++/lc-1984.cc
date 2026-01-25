#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        const int length = nums.size();
        sort(nums.begin(), nums.end());
        auto result {INT_MAX};

        for(int i = 0, j = k - 1; j < length; j++, i++){
            result = min(result, nums[j] - nums[i]);
        }

        return result;
    }
};
