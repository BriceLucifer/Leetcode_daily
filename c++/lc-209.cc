#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;


// 滑动窗口搭配双指针
class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int size {INT_MAX};

        for (int right = 0; right < n; right++){
            sum += nums[right];
            while (sum >= target) {
                size = min(size, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return size == INT_MAX ? 0 : size;
    }
};

int main(){
    auto target = 20;
    auto nums = vector<int>{2,16,14,15};
    auto s = Solution();
    auto length = s.minSubArrayLen(target, nums);
    cout << length << "\n";
    return 0;
}
