#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;

        // maintain the low and high, if low and high change, so the mid will change
        // low _____mid________ high
        // mid = (high - low) / 2 + high
        // the given array is all ordered from small to big
        // target > nums[mid] => low = mid + 1
        // target < nums[mid] => high = mid - 1
        while(low <= high) {
            auto mid = low + (high - low) / 2;
            if (nums[mid] == target ) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};
