#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.front() == nums.back()){
            return 0;
        }
        if (nums.size() <= 2) return 0;

        auto count {0};
        for(int i = 1; i < nums.size() - 1; i++){
            if (nums[i] > nums.front() && nums[i] < nums.back()){
                count += 1;
            }
        }

        return count;
    }
};
