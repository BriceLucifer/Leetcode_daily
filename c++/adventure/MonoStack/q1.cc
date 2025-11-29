#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        auto size = prices.size();
        if (size == 1) {
            return {prices[0]};
        }
        auto result = vector<int>(size, 0);

        // price[i]
        auto buffer = prices.begin();
        // price[j]
        auto compare = buffer + 1;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j){
                if (prices[i] >= prices[j]) {
                    result[i] = prices[i] - prices[j];
                    break;
                }
                if ( j == size - 1) {
                    result[i] = prices[i];
                }
            }
        }

        result.back() = prices.back();
        return result;
    }
};

int main() {
    auto prices = vector<int>{10,1,1,6};
    auto s = Solution();
    auto result = s.finalPrices(prices);

    for (auto x: result) {
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}
