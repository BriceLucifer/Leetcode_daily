class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1000000007LL;

        long long a = 6; // ABA
        long long b = 6; // ABC

        for (int i = 2; i <= n; ++i) {
            long long na = (3 * a + 2 * b) % MOD;
            long long nb = (2 * a + 2 * b) % MOD;
            a = na;
            b = nb;
        }

        return (int)((a + b) % MOD);
    }
};
/*
 * a[i]：第 i 行是 Type A 的方案数
 b[i]：第 i 行是 Type B 的方案数
 初始（i=1）：
 a = 6, b = 6
 转移（从第 i-1 行到第 i 行）：
 新的 Type A：
 从 A 来：3 * a
 从 B 来：2 * b
 a' = 3a + 2b
 新的 Type B：
 从 A 来：2 * a
 从 B 来：2 * b
 b' = 2a + 2b
 最后答案：(a + b) % MOD
 */
