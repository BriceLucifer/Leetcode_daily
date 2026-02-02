
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int sign = 1;
        int i = 0;
        int n = s.size();

        // 1️⃣ 跳过前导空格
        while (i < n && s[i] == ' ') i++;

        // 2️⃣ 处理符号
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3️⃣ 读取数字
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            if (result > (LLONG_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        long long ans = result * sign;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};
