#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int length = prices.size();
        auto result {0};

        for(int i = 1; i < length; i++){
            result += max(prices[i] - prices[i-1], 0);
        }

        return result;
    }
};
