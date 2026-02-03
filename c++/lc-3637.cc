#include <vector>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        auto p {0};
        int n = nums.size();
        auto q {0};

        for(int i = 1; i < n; i++) {
            if (nums[i] <= nums[i-1]) {
                // 1 0 1 2 3
                p = i - 1;
                break;
            }
        }

        if (p <= 0) {
            return false;
        }

        for(int i = p + 1; i < n; i++){
            if (nums[i] >= nums[i-1]){
                q = i - 1;
                break;
            }
        }

        if (q >= n - 1 || q == p){
            return false;
        }

        for(int i = q + 1; i < n; i++){
            if (nums[i] <= nums[i-1]){
                return false;
            }
        }

        return p > 0 && p < q && q < n - 1;
    }
};
