#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int size = prices.size();
       if (size == 1) return 0;

       auto minPrice = prices[0];
       auto maxProfit = 0;
       for(int i = 0; i < size; i++){
           minPrice = min(minPrice, prices[i]);
           maxProfit = max(prices[i] - minPrice, maxProfit);
       }
       return maxProfit;
    }
};
