#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /*
         * You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

         Train tickets are sold in three different ways:

         a 1-day pass is sold for costs[0] dollars,
         a 7-day pass is sold for costs[1] dollars, and
         a 30-day pass is sold for costs[2] dollars.
         The passes allow that many days of consecutive travel.

         For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
         Return the minimum number of dollars you need to travel every day in the given list of days.
         */

        int n = days.size();
        vector<int> dp = vector<int>(n+1, 0);

        for (int i = 1; i <= n; i++){
            // for day 1
            int cur = days[i-1];
            dp[i] = dp[i-1] + costs[0];

            // for day 7
            int j = i - 1;
            while(j >= 0 && cur - days[j] < 7){
                j--;
            }
            dp[i] = min(dp[i], dp[j+1] + costs[1]);

            // for day 30
            j = i - 1;
            while (j >= 0 && cur - days[j] < 30) {
                j--;
            }
            dp[i] = min(dp[i], dp[j+1] + costs[2]);
        }

        return dp[n];

    }
};
