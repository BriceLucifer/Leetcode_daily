#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;
/*
 * Return the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 You may assume that you have an infinite number of each kind of coin.
 Example 1:
 Input: coins = [1,2,5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 Example 2:
 Input: coins = [2], amount = 3
 Output: -1
 Example 3:
 Input: coins = [1], amount = 0
 Output: 0
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        auto dp = vector<int>(amount + 1, amount + 1);
        dp[0] = 0;

        for(auto i = 1; i < amount + 1; i++){
            for(auto coin: coins){
                if (i >= coin && dp[i-coin] != amount + 1){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
