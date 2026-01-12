#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int s1_len = s1.size();
        const int s2_len = s2.size();

        vector<vector<int>> dp(s1_len + 1, vector<int>(s2_len + 1, 0));

        // s2 为空
        for(int i = 1; i <= s1_len; i++){
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        // s1 为空
        for(int j = 1; j <= s2_len; j++){
            dp[0][j] = dp[0][j] + s2[j - 1];
        }

        for(int i = 1; i <= s1_len; i++){
            for(int j = 1; j <= s2_len; j++){
                if (s1[i - 1] == s2[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        dp[i - 1][j] + s1[i - 1],
                        dp[i][j - 1] + s2[j - 1]
                    );
                }
            }
        }

        return dp[s1_len][s2_len];
    }
};
