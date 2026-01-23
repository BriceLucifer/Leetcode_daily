#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<int> p{};
        auto result {0};
        for(int i = prices.size() - 1; i >= 0; i--){
            if (p.empty()){
                p.push(prices[i]);
            } else {
                result = max(result, p.top() - prices[i]);
                p.push(prices[i]);
            }
        }

        return result;
    }
};
