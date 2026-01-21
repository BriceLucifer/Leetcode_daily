#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int n = nums.size();

        set<int> s{};
        // x exist [i, j]
        // nums[i] == nums[j]
        for(int i = 0; i < n; i++){
            int x = nums[i];

            auto it = s.find(x);
            if (it != s.end()) {
                return true;
            }

            s.insert(x);

            if (s.size() > k){
                s.erase(nums[i - k]);
            }
        }

        return false;
    }
};
