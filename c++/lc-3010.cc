#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        const int length = nums.size();
        auto result {INT_MAX};
        if (length == 3) return accumulate(nums.begin(), nums.end(), 0);
        auto first = nums.front();

        for(int j = 1; j < length; j++){
            for(int z = j+1; z < length; z++){
                result = min(result,nums[j]+nums[z]+first);
            }
        }

        return result;

    }
};
