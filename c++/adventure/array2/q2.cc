#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        auto result = vector<int>(nums.size(), 0);

        for (int a = 0; a < nums.size(); ++a) {
            for (int b = 0; b < nums.size(); ++b) {
                if (nums[a] > nums[b] ) {
                    result[a] += 1;
                }
            }
        }

        return result;
    }
};

int main() {
    auto nums = vector<int>{7,7,7,7};
    auto s = Solution();
    auto result = s.smallerNumbersThanCurrent(nums);

    for (auto i: result) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
