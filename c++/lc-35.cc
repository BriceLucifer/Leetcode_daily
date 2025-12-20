#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto left = 0;
        auto right = nums.size();
        while (left <= right) {
            auto mid = left + (right - left >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            }else if (nums[mid] > target){
                right = mid - 1;
            }else {
                return mid;
            }
        }
        return left;
    }
};

int main(){
    auto nums = vector<int>{1, 3, 5, 6};
    auto target = 2;
    auto result = Solution().searchInsert(nums, target);
    cout << result << '\n';
}
