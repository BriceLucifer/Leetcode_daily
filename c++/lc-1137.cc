#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp{0, 1, 1};
        if (n < 3) return dp[n];

        for(int i = 3; i < n + 1; i++){
            dp.push_back(dp[i-1] + dp[i-2] + dp[i-3]);
        }

        return dp.back();
    }
};
