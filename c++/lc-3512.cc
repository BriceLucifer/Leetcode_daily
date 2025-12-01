#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        auto operation = 0;
        if (sum % k == 0) {
            return operation;
        }

        if (sum < k) {
            return sum;
        }

        return sum % k;
    }
};

int main() {
    auto nums = vector<int>{4, 1, 3};
    auto k = 4;
    auto s = Solution();

    auto maxOperation = s.minOperations(nums, k);

    cout << maxOperation << "\n";
    return 0;
}
