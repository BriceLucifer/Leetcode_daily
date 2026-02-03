#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        auto result {LLONG_MIN >> 2};
        auto f1 {LLONG_MIN >> 2}, // f1 第一段 up
             f2 {LLONG_MIN >> 2}, // f2 第二段 down
             f3 {LLONG_MIN >> 2}; // f3 第三段 up

        const int n = nums.size();

        for(int i = 1; i < n; i++){
            long long x = nums[i - 1], y = nums[i];

            // 如果是递增加 判断第一段还是第三段
            if (x < y){
                // 第三段：从f2开始 || 第三段延续
                f3 = max(f3, f2) + y;
                // 判断是否有必要 + y
                result = max(result, f3);

                f2 = LLONG_MIN >> 2;

                // 第一段x开始 || 第一段延续
                f1 = max(f1, x) + y;
            } else if (x > y) {
                // 第二段：从f1开始 || 第二段延续
                f2 = max(f1, f2) + y;
                f1 = LLONG_MIN >> 2;
                f3 = LLONG_MIN >> 2;

            } else {
                f1 = f2 = f3 = LLONG_MIN >> 2;
            }
        }

        // 保证至少有一个子数组 那么result不会返回初始值
        return result;
    }
};
