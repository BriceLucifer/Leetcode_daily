#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        auto n = 0;
        auto times = 0;
        for (auto i: nums) {
            if (i == 1) {
                times += 1;
            } else {
                if (times > n) {
                    n = times;
                    times = 0;
                } else {
                    times = 0;
                }
            }
        }

        n = times > n ? times : n;

        return n;
    }
};

int main() {
    vector<int> nums = {1,1,0,1,1,1};
    auto s = Solution();
    auto r = s.findMaxConsecutiveOnes(nums);

    cout << r ;

    return 0;
}
