#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result {0};
        if (prices.size() == 1){
            return 1;
        }

        int i = 0;
        vector<vector<int>> other;
        vector<int> temp;

        // [8, 6, 7, 7]
        for(; i < prices.size(); i++){
            if (temp.empty()) {
                temp.push_back(prices[i]);
            } else {
                if (temp.back() - prices[i] == 1){
                    temp.push_back(prices[i]);
                } else {
                    other.push_back(temp);
                    temp.clear();
                    temp.push_back(prices[i]);
                }
            }
        }

        other.push_back(temp);


        for(auto v: other) {
            result += (v.size() * (v.size() + 1)) >> 1;
        }

        return result;
    }
};

int main(){
    auto prices = vector<int>{3,2,1,4};
    auto s = Solution();
    auto result = s.getDescentPeriods(prices);
    cout << result << '\n';

    return 0;
}
