#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto write = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[write] = nums[i];
                write += 1;
            }
        }

        for(; write < nums.size(); write++){
            nums[write] = 0;
        }

        return ;
    }
};
