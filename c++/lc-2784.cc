#include <algorithm>
#include <vector>

using namespace std;
//
// base[n] = {1...n, n};
// check if the nums is base array
// 1. the solution is first sort the num using sort
// 2. check the back of the array == n
// 3. for(iteration) from 1 to n tips: using index of the array, be carefully to minus 1;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size() - 1;

        if (nums.back() != size) {
            return false;
        }

        for(int i = 1; i <= size; i++){
            if (nums[i-1] != i) return false;
        }

        return true;
    }
};
