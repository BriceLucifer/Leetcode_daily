#include <iostream>

using namespace std;

// 经典爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        // dp "hello world"
        if (n == 1) return 1;
        if (n == 2) return 2;

        auto prev {1};
        auto next {2};
        auto sum {0};
        for (auto i = 3; i <= n; i++) {
            sum = prev + next;
            prev = next;
            next = sum;
        }

        return sum;
    }
};

int main() {
    int stairs {4};
    Solution s {};

    cout << "4 stairs: " << s.climbStairs(4) << " ways"<< endl;
    cout << "5 stairs: " << s.climbStairs(5) << " ways"<< endl;
    cout << "1 stairs: " << s.climbStairs(1) << " ways"<< endl;
}
