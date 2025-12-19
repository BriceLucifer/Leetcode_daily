#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 最快的速度
        auto max_speed {0LL};
        for(auto &i: piles){
            max_speed = std::max(max_speed, static_cast<long long>(i));
        }

        // 希望刚刚好的速度
        auto small {1LL};
        auto check = [&](int k) -> long {
            long hour = 0;
            for(auto &i: piles){
                hour += i / k;
                if (i % k > 0){
                    hour++;
                }
            }
            return hour;
        };

        while (small <= max_speed) {
            auto mid = (small + max_speed) >> 1;
            if (check(mid) <= h) {
                // if h_temp < h 那么意味着我的max就得缩小到mid
                max_speed = mid - 1;
            } else {
                small = mid + 1;
            }
        }

        return small;
    }
};

int main(){
    auto v = vector<int>{3,6,7,11};
    auto s {Solution()};
    cout << s.minEatingSpeed(v, 8)<< '\n';
}
