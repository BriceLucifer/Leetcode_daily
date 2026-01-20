#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++){
            // 1 1 1 = 4 + 2 + 1
            // 1 | 0 1
            // 1 | 1 0
            //
            // 1 0 1
            // 1 0 0
            //
            // 11
            // 1 0 1 1
            // 1 0 1 1
            // 1 0 0 1 = 8 + 1
            // 1 0 1 0 = 8 + 2
            // 13
            // 1 1 0 1
            // 1 1 0 0
            // 31
            // 1 1 1 1 1 = 16 + 8 + 4 + 2 + 1
            // 1 0 0 0 0
            // 0 1 1 1 1
            if (nums[i] != 2 && nums[i] != 1) {
                int n = 0;
                // find the first zero and replace it with lower zero change to zero
                while ((nums[i] >> n) & 1) {
                    n++;
                }
                ans[i] = nums[i] - (1 << (n - 1));
            }
        }

        return ans;
    }
};
