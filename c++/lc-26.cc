#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto k = 0;
        auto j = 1;
        int size = nums.size();
        // nums = [0,0,1,1,1,2,2,3,3,4]
        // nums = [1,1,2]
        for(; j < size; j++){
            if (nums[k] != nums[j]){
                k++;
                nums[k] = nums[j];
            }
        }

        return k + 1;

    }
};
