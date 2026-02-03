#include <climits>
#include <cstdlib>

// 这类题目需要注意溢出
// 技巧在于 关注 INT_MAX / 10 和 INT_MIN / 10
// mod > 7 与 mod < -8
// 直觉:
//  对于这类题目 千万不要转abs(int) 不然反而不好处理
class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int a = 0;

        while (x != 0) {
            auto mod = x % 10;
            x = x / 10;

            if (a > INT_MAX / 10 || (a == INT_MAX / 10 && mod > 7)) return 0;
            if (a < INT_MIN / 10 || (a == INT_MIN / 10 && mod < -8)) return 0;
            a = a * 10 + mod;
        }

        return a;
    }
};
