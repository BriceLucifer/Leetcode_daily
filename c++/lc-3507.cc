#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        auto ops{0};
        while (true) {
            auto sorted {true};
            const int n = nums.size();
            for(int i = 1; i < n; i++){
                if (nums[i] < nums[i-1]){
                    sorted = false;
                    break;
                }
            }

            if (sorted) break;
            auto mini {INT_MAX};
            auto idx {-1};
            for(int i = 1; i < n; i++){
                const int value = nums[i] + nums[i-1];
                if (value < mini){
                    mini = value;
                    idx = i;
                }
            }
            nums[idx - 1] = mini;
            nums.erase(nums.begin() + idx);
            ops += 1;
        }

        return ops;
    }
};
