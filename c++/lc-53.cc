#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// kadane algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto result = INT_MIN;
        auto cur = 0;

        for(auto n: nums){
            cur = max(n, cur + n);
            result = max(cur, result);
        }

        return result;
    }
};
