#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        auto k = 0;

        for(int i = 0; i < size; i++){
            if (nums[i] != val){
                nums[k] = nums[i];
                k += 1;
            }
        }

        return k;

    }
};
