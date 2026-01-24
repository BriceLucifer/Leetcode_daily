#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int length = nums.size();
        if (length == 1) return true;
        if (nums.front() == 0) return false;

        auto maxReach {0};
        for(int i = 0; i < length - 1; i++){
            if (i > maxReach) return false;
            else {
                maxReach = max(maxReach, i+nums[i]);
            }
        }
        return maxReach >= length - 1;
    }
};
