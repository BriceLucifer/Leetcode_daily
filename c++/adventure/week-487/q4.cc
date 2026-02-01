#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;

        vector<int> up0(n, 1), down0(n, 1), up1(n, 1), down1(n, 1);
        int ans = 1;

        for (int i = 1; i < n; i++) {
            // ---------- no deletion (0) ----------
            if (nums[i - 1] < nums[i]) {
                up0[i] = down0[i - 1] + 1;
                // down0[i] stays 1
            } else if (nums[i - 1] > nums[i]) {
                down0[i] = up0[i - 1] + 1;
                // up0[i] stays 1
            }
            // equal -> both stay 1

            // ---------- one deletion used (1), case A: don't delete i-1 ----------
            if (nums[i - 1] < nums[i]) {
                up1[i] = max(up1[i], down1[i - 1] + 1);
            } else if (nums[i - 1] > nums[i]) {
                down1[i] = max(down1[i], up1[i - 1] + 1);
            }

            // ---------- one deletion used (1), case B: delete i-1, connect i-2 -> i ----------
            if (i >= 2) {
                if (nums[i - 2] < nums[i]) {
                    up1[i] = max(up1[i], down0[i - 2] + 1);
                } else if (nums[i - 2] > nums[i]) {
                    down1[i] = max(down1[i], up0[i - 2] + 1);
                }
            }

            ans = max({ans, up0[i], down0[i], up1[i], down1[i]});
        }

        return ans;
    }
};
©leetcode
