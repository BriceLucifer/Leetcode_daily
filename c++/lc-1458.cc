#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        const int m = nums2.size();

        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, INT_MIN));
        for(int i = 0; i < n ; i++){
            for (int j = 0; j < m; j++){
                auto prod = nums1[i] * nums2[j];
                dp[i][j] = prod;

                if (i > 0 && j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + prod);
                }

                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }

                if (j > 0){
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }

        // return the last value
        return dp.back().back();
    }
};
