constexpr int MX = 51;
long long comb[MX][MX];

auto init = [] {
    // 预处理组合数
    for (int i = 0; i < MX; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    return 0;
}();

class Solution {
public:
    long long nthSmallest(long long n, int k) {
        long long ans = 0;
        for (int i = 49; k > 0; i--) {
            long long c = comb[i][k]; // 第 i 位填 0 的方案数
            if (n > c) { // n 比较大，第 i 位必须填 1
                n -= c;
                ans |= 1LL << i;
                k--; // 维护剩余的 1 的个数
            }
        }
        return ans;
    }
};
