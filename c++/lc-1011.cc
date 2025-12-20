#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // find the fast
        auto right = accumulate(weights.begin(), weights.end(), 0);
        // the speed we want just fine
        auto left = 0;
        for(auto &i: weights){
            if (i > left){
                left = i;
            }
        }

        function<int(int)> check = [&](int k) -> long {
            long days = 1;
            auto temp = 0;
            for(auto &i: weights){
                if (temp + i <= k){
                    temp += i;
                } else {
                    days++;
                    temp = i;
                }
            }
            return days;
        };

        // bineary search
        while (left <= right) {
            auto mid = (left + right) >> 1;
            if (check(mid) <= days){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main(){
    auto weights = vector<int>{1,2,3,1,1};
    auto days = 4;
    auto s = Solution().shipWithinDays(weights, days);
    cout << s << '\n';
}
