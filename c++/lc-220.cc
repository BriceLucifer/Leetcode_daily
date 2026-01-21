#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        const int n = nums.size();
        // abs(nums[i] - nums[j]) <= valueDiff
        // nums[i] - valueDiff <= nums[j] <= valueDiff + nums[i]
        // nums[i] = x

        // abs(i - j) = indexDiff
        // x exits in |i...j|
        // x exits in |nums[i] - valueDiff...valueDiff + nums[i]|
        set<long long> s{};

        for(int i = 0; i < n; i++){
            long long x = nums[i];

            auto it = s.lower_bound(x - valueDiff);
            while (it != s.end() && *it <= x + valueDiff) {
                return true;
            }

            s.insert(x);

            if (s.size() > indexDiff){
                s.erase(static_cast<long long>(nums[i - indexDiff]));
            }
        }

        return false;
    }
};
