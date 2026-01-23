#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const auto length = prices.size();
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int cash1 = 0, cash2 = 0;

        for (int p : prices) {
            hold1 = max(hold1, -p);
            cash1 = max(cash1, hold1 + p);
            hold2 = max(hold2, cash1 - p);
            cash2 = max(cash2, hold2 + p);
        }

        return cash2;

    }
};
