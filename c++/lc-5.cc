#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans_left = 0, ans_right = 0;

        // 奇回文串
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // 循环结束后，s[l+1] 到 s[r-1] 是回文串
            if (r - l - 1 > ans_right - ans_left) {
                ans_left = l + 1;
                ans_right = r; // 左闭右开区间
            }
        }

        // 偶回文串
        for (int i = 0; i < n - 1; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > ans_right - ans_left) {
                ans_left = l + 1;
                ans_right = r; // 左闭右开区间
            }
        }

        return s.substr(ans_left, ans_right - ans_left);
    }
};
