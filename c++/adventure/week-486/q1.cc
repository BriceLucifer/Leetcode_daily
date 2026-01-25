#include <vector>

using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        const int length = nums.size();
        auto prefix {0};
        for(int i = length - 1; i - 1>= 0; i--){
            if (nums[i] <= nums[i-1]) {
                prefix = i;
                break;
            }
        }

        return prefix;
    }
};
